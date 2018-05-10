//
// Created by tldlir001 on 2018/05/10.
//

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

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
        int numCh; //-c
        std::vector<A> data;

    public:
        Audio(int sps, int sz, int nc, std::vector d);

        void load(std::string name);


        A operator+(const A a);

        ~Audio();


    };
}



#endif //AUDIOMANIPULATION_AUDIO_H
