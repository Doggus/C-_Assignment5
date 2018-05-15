#include "Audio.h"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    
    //------------------------
    //audio.load("sample_input/beez18sec_44100_signed_8bit_mono.raw"); //mono
    //audio.load("sample_input/countdown40sec_44100_signed_16bit_stereo.raw");
    //audio.save("Test1.raw");
    //-----------------------
    cout << "hi" << endl;
    
    std::vector<int8_t> v = {1,2,3,4,5,6,7};
    tldlir001::Audio<int8_t> audio(v);
    tldlir001::Audio<int8_t> audio2 = audio.FadeIn(1,3,);

    for (int i = 0; i < audio2.getData().size(); ++i)
    {
        cout << audio2.getData()[i] << endl;
    }


    return 0;
}