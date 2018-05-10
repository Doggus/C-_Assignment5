//
// Created by tldlir001 on 2018/05/10.
//

#include <iterator>
#include "Audio.h"

using namespace std;

tldlir001::Audio::Audio(int sps, int sz, int nc, std::vector d)
{

    sPS = sps;
    size = sz;
    numCh = nc;
    data = d;

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
        std::string line;
        int c = 0;

        while(std::getline(in, line))
        {
            data[c] = line;
            ++c;
        }



    }

}

template <typename A>
A operator+(const A a)
{

}








tldlir001::Audio::~Audio()
{

}