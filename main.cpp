#include "Audio.h"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    

    tldlir001::Audio<int8_t> audio;
    audio.load("sample_input/beez18sec_44100_signed_8bit_mono.raw");



    audio.save("Test1.raw");



    return 0;
}