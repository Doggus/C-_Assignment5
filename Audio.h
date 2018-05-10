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
    template <typename A>
    class Audio
    {
    private:
        int sPS; //-r
        int size; //-b
        int channels; //-c
        std::vector<A> data;

    public:
        template <typename I>
        Audio(int sps, int sz, int nc, std::string name)
        {

            sPS = sps;
            size = sz;
            channels = nc;

            std::ifstream in(name,std::ifstream::binary);

            if(!in)
            {
                std::cout << "Couldn't open file" << std::endl;
            }
            else
            {
                in.seekg (0, in.end);
                long length = in.tellg();// file size
                in.seekg (0, in.beg);

                char * buffer = new char [length];

                in.read (buffer,length);

                for (int i = 0; i < length; ++i)
                {
                    data[i] = buffer[i];
                }


                std::cout<<data[0] << std::endl;
                //NumberOfSamples = fileSizeInBytes / (sizeof(intN_t) * channels)
                //int samples = length/ (sizeof(intN_t)) * channels;

                //deletes buffer from memory
                delete[] buffer;

            }
        }





        A operator+(const A a);

        ~Audio();


    };
}



#endif //AUDIOMANIPULATION_AUDIO_H
