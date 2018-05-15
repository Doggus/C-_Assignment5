#include "Audio.h"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    

    //------------------------
    // std::vector<pair<int,int>> v = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4),make_pair(5,5),make_pair(6,6),make_pair(7,7)};
    // tldlir001::Audio<pair<int,int>> audio(v);
    // tldlir001::Audio<pair<int,int>> audio1(v);
    // std::pair<int,int> p = make_pair(2,5);
    // tldlir001::Audio<pair<int,int>> audio2 = audio.RangedAdd(1,audio,audio1,p);

    // for (int i = 0; i < audio2.getData().size(); ++i)
    // {
    //     cout<<audio2.getData()[i].second <<endl;
    // }
    //------------------------
    //audio.load("sample_input/beez18sec_44100_signed_8bit_mono.raw"); //mono
    //audio.load("sample_input/countdown40sec_44100_signed_16bit_stereo.raw");
    //audio.save("Test1.raw");
    //-----------------------
    // std::vector<pair<int8_t,int8_t>> v = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    // tldlir001::Audio<pair<int8_t,int8_t>> audio(v);
    // std::pair<float,float> p = audio.ComputeRMS();

    //cout << p.first << endl;



    return 0;
}