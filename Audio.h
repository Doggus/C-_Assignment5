//
// Created by tldlir001 on 2018/05/10.
//

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
# include <cstdint>
#include <iterator>

#ifndef AUDIOMANIPULATION_AUDIO_H
#define AUDIOMANIPULATION_AUDIO_H

namespace tldlir001
{
    //A can be 8 or 16 bit value
    template <typename A>
    class Audio
    {
    private:
        //std::vector<A> data;

    public:
        std::vector<A> data;

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

        



        //~Audio();


    };

    //partial specialisation in the case where we are reading in pair of values that can be 8 or 16 bit
    template <typename A>
    class Audio <std::pair<A,A>>
    {
    private:
        //std::vector<std::pair<A,A>> data;

    public:
        std::vector<std::pair<A,A>> data;

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
        

       // ~Audio();
    };
}



#endif //AUDIOMANIPULATION_AUDIO_H
