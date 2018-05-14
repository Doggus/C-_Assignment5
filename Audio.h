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

        Audio(std::vector<A> v)
        {
            data = v;
        }

        Audio<A> operator+(const Audio<A> &rhs)
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

        Audio(std::vector<std::pair<A,A>> v)
        {
            data = v;
        }

        Audio operator+(const Audio &rhs) const
        {
            std::vector<std::pair<A,A>> v;
            for (int i = 0; i < data.size(); ++i)
            {
                v[i].first = this->data[i].first + rhs.data[i].first;
                v[i].second = this->data[i].second + rhs.data[i].second;
            }

            Audio <A> audio(v);

            return audio;
        }

       // ~Audio();
    };
}



#endif //AUDIOMANIPULATION_AUDIO_H
