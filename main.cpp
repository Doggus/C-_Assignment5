#include "Audio.h"
#include <iostream>

int main()
{
    tldlir001::Audio(44100,16,1,"sample_input/beez18sec_44100_signed_8bit_mono.raw");
    //sample_input/beez18sec_44100_signed_8bit_mono.raw
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}