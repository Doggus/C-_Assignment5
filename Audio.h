//
// Created by tldlir001 on 2018/05/10.
//

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include <ostream>
#include <cstdint>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <memory>

#ifndef AUDIOMANIPULATION_AUDIO_H
#define AUDIOMANIPULATION_AUDIO_H

namespace tldlir001
{
    //A can be 8 or 16 bit value
    template <typename A>
    class Audio
    {
    private:
        std::vector<A> data;

    public:

        std::vector<A> getData()
        {
            return data;
        }

        //default constructor
        Audio()
        {
            data;
        }

        //Normal constructor
        Audio(std::vector<A> v)
        {
            data = v;
        }

        //copy constructor
        Audio(const Audio<A> &audio)
        {
            for (int i = 0; i < audio.data.size(); ++i)
            {
                data.push_back(audio.data[i]);
            }
        }

        //copy assignment operator
        Audio &operator=(const Audio<A> &audio)
        {
            for (int i = 0; i < audio.data.size(); ++i)
            {
                data.push_back(audio.data[i]);
            }

            return *this;
        }

        //move constructor
        Audio(Audio<A> &&audio)
        {
            for (int i = 0; i < audio.data.size(); ++i)
            {
                data.push_back(audio.data[i]);
            }

            //ensentially deletes old audio 
            audio.data.erase(audio.data.begin(),audio.data.end());
        }

        //move assignment operator
        Audio &operator=(Audio<A> &&audio) 
        {
            for (int i = 0; i < audio.data.size(); ++i)
            {
                data.push_back(audio.data[i]);
            }

            audio.data.erase(audio.data.begin(),audio.data.end());

            return *this;
        }

        //concatenate
        Audio operator|(const Audio &rhs)
        {
            std::vector<A> v;
            for (int i = 0; i < data.size(); ++i)
            {
                v.push_back(this->data[i]);
            }

            for (int j = 0; j < rhs.data.size(); ++j)
            {
                v.push_back(rhs.data[j]);
            }

            Audio <A> audio(v);

            return audio;
        }

        //Volume (may need to some number rounding but not sure yet)
        Audio operator*(const std::pair<float,float> p)
        {
            std::vector<A> v;
            for (int i = 0; i < data.size(); ++i)
            {
                v.push_back(this->data[i]*p.first);
            }

            Audio <A> audio(v);

            return audio;
        }

        //Add
        Audio operator+(const Audio &rhs)
        {
            std::vector<A> v;
            for (int i = 0; i < data.size(); ++i)
            {
                //push_back is used when the vector hasn't been assigned memory space beforehand
                A result = this->data[i] + rhs.data[i];
                v.push_back(result);
            }

            Audio <A> audio(v);

            return audio;
        }

        //Cut
        Audio operator^(const std::pair<int,int> p)
        {
            Audio<A> copy = *this;
            std::vector<A> v;
            copy.data.erase(copy.data.begin()+p.first,copy.data.begin()+p.second);

            for (int i = 0; i < copy.data.size(); ++i)
            {
                v.push_back(copy.data[i]);
            }

            Audio <A> audio(v);

            return audio;
        }

        Audio Reverse()
        {
            Audio<A> copy = *this;
            std::reverse(copy.data.begin(),copy.data.end());
            return copy;
        }

        Audio RangedAdd(int SampleRate, Audio &a1, Audio &a2, std::pair<int,int> p)
        {
            // samples are in seconds, so to get the number of samples : 
            // multiply sampleRate(terminal parameter) with the pair intervals(seconds)
            // e.g. number of samples per second * seconds passed = number of samples to add (range)
            
            std::vector<A> v;

            int sampleBegin = SampleRate*p.first;
            int sampleEnd = SampleRate*p.second;

            for (int i = sampleBegin; i < sampleEnd; ++i)
            {
                 v.push_back(a1.data[i] + a2.data[i]);   
            }
            
            Audio <A> audio(v);
            return audio;
            
        }

        float ComputeRMS()
        {
             Audio<A> copy = *this;
             std::vector<A> pwr;
             for (int i = 0; i < copy.data.size(); ++i)
             {
                 pwr.push_back(copy.data[i]*copy.data[i]); //power of 2
             }

             float sum = std::accumulate(pwr.begin(),pwr.end(), 0);
             float avgSqr = sum/(copy.data.size());
             float RMS = sqrt(avgSqr);
             return RMS;
        }

        Audio Normalization()
        {}


        void load(std::string name)
        {
            std::ifstream in(name);

            if(!in)
            {
                std::cout << "Couldn't open file" << std::endl;
            }
            else
            {
                // get length of file: (got from online source given to us)
                in.seekg (0, in.end);
                int fileLength = in.tellg();
                in.seekg (0, in.beg);

                int bitSize = sizeof(A); //A is 8 bit or 16 bit
                data.resize(fileLength/bitSize);

                for (int i = 0; i < fileLength; ++i)
                {
                    in.read((char *) &data[i], bitSize); //reads value of bitSize into data[i]
                }

                //Alternative way of doing things
                /*
                int count = 0;
                while(in.tellg() < fileLength) //while not at the end of file
                {
                    //data reads in the number of bits = to template type
                    in.read((char *) &data[count], bitSize); 
                    ++count;
                }
                */

                

                in.close();
            }
        }

        void save(std::string name)
        {
            std::ofstream out("Audio_Output/" + name, std::ios::binary);
            int bitSize = sizeof(A);

            for (int i = 0; i < data.size(); ++i)
            {
                out.write((char*)&data[i],bitSize);
            }

            out.close();
           
        }


        ~Audio(){ /*nothing to explicitly destruct*/ }


    };

    //partial specialisation in the case where we are reading in pair of values that can be 8 or 16 bit
    template <typename A>
    class Audio <std::pair<A,A>>
    {
    private:
        std::vector<std::pair<A,A>> data;

    public:

        std::vector<std::pair<A,A>> getData()
        {
            return data;
        }

        //default constructor
        Audio()
        {
            data;
        }

        //normal constructor
        Audio(std::vector<std::pair<A,A>> v)
        {
            data = v;
        }

        //copy constructor
        Audio(const Audio<std::pair<A,A>> &audio)
        {
            for (int i = 0; i < audio.data.size(); ++i)
            {
                data.push_back(audio.data[i]);
            }
        }

        //copy assignment operator
        Audio &operator=(const Audio<std::pair<A,A>> &audio)
        {
            for (int i = 0; i < audio.data.size(); ++i)
            {
                data.push_back(audio.data[i]);
            }

            return *this;
        }

        //move constructor
        Audio(Audio<std::pair<A,A>> &&audio)
        {
            for (int i = 0; i < audio.data.size(); ++i)
            {
                data.push_back(audio.data[i]);
            }

            //ensentially deletes old audio 
            audio.data.erase(audio.data.begin(),audio.data.end());
        }

        //move assignment operator
        Audio &operator=(Audio<std::pair<A,A>> &&audio) 
        {
            for (int i = 0; i < audio.data.size(); ++i)
            {
                data.push_back(audio.data[i]);
            }

            audio.data.erase(audio.data.begin(),audio.data.end());

            return *this;
        }

        //Concatanate
        Audio operator|(const Audio &rhs)
        {
            std::vector<std::pair<A,A>> v;
            for (int i = 0; i < data.size(); ++i)
            {
                v.push_back(this->data[i]);
            }

            for (int j = 0; j < rhs.data.size(); ++j)
            {
                v.push_back(rhs.data[j]);
            }

            Audio <std::pair<A,A>> audio(v);

            return audio;
        }

        //Volume
        Audio operator*(const std::pair<float,float> p)
       {
            std::vector<std::pair<A,A>> v;
            for (int i = 0; i < data.size(); ++i)
            {
                v.push_back(std::make_pair(this->data[i].first*p.first,this->data[i].second*p.second));
            }

            Audio <std::pair<A,A>> audio(v);

            return audio;
        }


        //Add
        Audio operator+(const Audio &rhs)
        {
            std::vector<std::pair<A,A>> v;
            for (int i = 0; i < data.size(); ++i)
            {
                v.push_back(std::make_pair(this->data[i].first + rhs.data[i].first,this->data[i].second + rhs.data[i].second));
            }

            Audio <std::pair<A,A>> audio(v);

            return audio;
        }

        Audio operator^(const std::pair<int,int> p)
        {
            Audio<std::pair<A,A>> copy = *this;
            std::vector<std::pair<A,A>> v;
            copy.data.erase(copy.data.begin()+p.first,copy.data.begin()+p.second);

            for (int i = 0; i < copy.data.size(); ++i)
            {
                v.push_back(copy.data[i]);
            }

            Audio <std::pair<A,A>> audio(v);

            return audio;
        }
        
        Audio Reverse()
        {
            Audio<std::pair<A,A>> copy = *this;
            std::reverse(copy.data.begin(),copy.data.end());
            return copy;
        }

        Audio RangedAdd(int SampleRate, Audio &a1, Audio &a2, std::pair<int,int> p)
        {
            // samples are in seconds, so to get the number of samples : 
            // multiply sampleRate(terminal parameter) with the pair intervals(seconds)
            // e.g. number of samples per second * seconds passed = number of samples to add (range)
            
            std::vector<std::pair<A,A>> v;

            int sampleBegin = SampleRate*p.first;
            int sampleEnd = SampleRate*p.second;

            for (int i = sampleBegin; i < sampleEnd; ++i)
            {
                 v.push_back(std::make_pair(a1.data[i].first + a2.data[i].first, a1.data[i].second + a2.data[i].second));   
            }
            
            Audio <std::pair<A,A>> audio(v);
            return audio;
            
        }

        std::pair<float,float> ComputeRMS()
        {
             Audio<std::pair<A,A>> copy = *this;
             std::vector<std::pair<A,A>> pwr;
             for (int i = 0; i < copy.data.size(); ++i)
             {
                 //square everything
                 pwr.push_back(std::make_pair(copy.data[i].first*copy.data[i].first, copy.data[i].second*copy.data[i].second));
             }

             float sumL = 0;
             float sumR = 0;
             for (int i = 0; i < copy.data.size(); ++i)
             {
                 sumL += pwr[i].first;
                 sumR += pwr[i].second;

             }

             float avgSqrL = sumL/(copy.data.size());
             float avgSqrR = sumR/(copy.data.size());
             float RMS_L = sqrt(avgSqrL);
             float RMS_R = sqrt(avgSqrR);
             std::pair<float,float> p = std::make_pair(RMS_L,RMS_R);
             return p;
        }




        void load(std::string name)
        {
            std::ifstream in(name);

            if(!in)
            {
                std::cout << "Couldn't open file" << std::endl;
            }
            else
            {
                // get length of file: (got from online source given to us)
                in.seekg (0, in.end);
                int fileLength = in.tellg();
                in.seekg (0, in.beg);

                int bitSize = sizeof(A); //A is 8 bit or 16 bit
                data.resize(fileLength/bitSize);

                A f;
                A s;
                std::pair<A,A> p;
                for (int i = 0; i < fileLength; ++i)
                {
                    //switches between each ear (pair.first = left ear | pair.second = right ear)

                    if(i % 2 == 0) //even
                    {
                        in.read((char *) f, bitSize);
                    }
                    else //odd
                    {
                        in.read((char *) s, bitSize);
                    }

                    if(i % 2 != 0)
                    {
                        p = make_pair(f,s);
                        data.push_back(p);
                    }
                    
                }

                in.close();
            }
        }

        void save(std::string name)
        {
            std::ofstream out("Audio_Output/" + name, std::ios::binary);
            int bitSize = sizeof(A);

            for (int i = 0; i < data.size(); ++i)
            {
                 out.write((char*)&data[i],bitSize);
            }  

            out.close();
           
        }

        ~Audio(){ /*nothing to explicitly destruct*/ }
    };
}



#endif //AUDIOMANIPULATION_AUDIO_H
