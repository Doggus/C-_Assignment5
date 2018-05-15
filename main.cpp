#include "Audio.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{

    int samplesPerSecond = stoi(argv[2]);
    int bitSize = stoi(argv[4]);
    int channel = stoi(argv[6]);
    string outputFile = argv[8];


    cout << samplesPerSecond << endl;
    cout << bitSize << endl;
    cout << channel << endl;
    cout << outputFile << endl;

    if (strcmp(argv[9], "-add")==0)
    {
        string inputFile1 = argv[10];
        string inputFile2 = argv[11];
        if(bitSize == 8)
        {
            if (channel == 1)
            {
                tldlir001::Audio<int8_t> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<int8_t> audio2;
                audio2.load(inputFile2);

                tldlir001::Audio<int8_t> audioAdd = audio1+audio2;
                string name = outputFile + "_" + to_string(samplesPerSecond) + "_8_mono.raw";
                audioAdd.save(name);

            }
            else
            {
                tldlir001::Audio<std::pair<int8_t,int8_t>> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<std::pair<int8_t,int8_t>> audio2;
                audio2.load(inputFile2);

                tldlir001::Audio<std::pair<int8_t,int8_t>> audioAdd = audio1+audio2;
                string name = outputFile + "_" + to_string(samplesPerSecond) + "_8_stereo.raw";
                audioAdd.save(name);
            }
        }
        else
        {
            if (channel == 1)
            {
                tldlir001::Audio<int16_t> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<int16_t> audio2;
                audio2.load(inputFile2);

                tldlir001::Audio<int16_t> audioAdd = audio1+audio2;
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_16_mono.raw";
                audioAdd.save(name);

            }
            else
            {
                tldlir001::Audio<std::pair<int16_t,int16_t>> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<std::pair<int16_t,int16_t>> audio2;
                audio2.load(inputFile2);

                tldlir001::Audio<std::pair<int16_t,int16_t>> audioAdd = audio1+audio2;
                string name = outputFile + "_" + to_string(samplesPerSecond) + "_16_stereo.raw";
                audioAdd.save(name);
            }
        }


        
    }
    else if(strcmp(argv[9], "-cut")==0)
    {
        string inputFile1 = argv[12];
        int r1 = stoi(argv[10]);
        int r2 = stoi(argv[11]);
        std::pair<int,int> range = make_pair(r1,r2);

        if(bitSize == 8)
        {
            if (channel == 1)
            {
                tldlir001::Audio<int8_t> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<int8_t> AudioCut = audio1^range;
                string name = outputFile + "_" + to_string(samplesPerSecond) + "_8_mono.raw";
                AudioCut.save(name);

            }
            else
            {
                tldlir001::Audio<std::pair<int8_t,int8_t>> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<std::pair<int8_t,int8_t>> AudioCut = audio1^range;
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_8_stereo.raw";
                AudioCut.save(name);
            }
        }
        else
        {
            if (channel == 1)
            {
                tldlir001::Audio<int16_t> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<int16_t> AudioCut = audio1^range;
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_16_mono.raw";
                AudioCut.save(name);

            }
            else
            {
                tldlir001::Audio<std::pair<int16_t,int16_t>> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<std::pair<int16_t,int16_t>> AudioCut = audio1^range;
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_16_stereo.raw";
                AudioCut.save(name);
            }
        }
    }
    else if(strcmp(argv[9], "-radd")==0)
    {
        int r1 = stoi(argv[10]);
        int r2 = stoi(argv[11]);
        string inputFile1 = argv[12];
        string inputFile2 = argv[13];
        std::pair<int,int> range = make_pair(r1,r2);

        if(bitSize == 8)
        {
            if (channel == 1)
            {
                tldlir001::Audio<int8_t> a;    
                
                tldlir001::Audio<int8_t> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<int8_t> audio2;
                audio1.load(inputFile2);

                tldlir001::Audio<int8_t> audioRangeAdd = a.RangedAdd(samplesPerSecond,audio1,audio2,range);
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_8_mono.raw";
                audioRangeAdd.save(name);

            }
            else
            {
                tldlir001::Audio<std::pair<int8_t,int8_t>> a;    
                
                tldlir001::Audio<std::pair<int8_t,int8_t>> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<std::pair<int8_t,int8_t>> audio2;
                audio1.load(inputFile2);

                tldlir001::Audio<std::pair<int8_t,int8_t>> audioRangeAdd = a.RangedAdd(samplesPerSecond,audio1,audio2,range);
                string name = outputFile + "_" + to_string(samplesPerSecond) + "_8_stereo.raw";
                audioRangeAdd.save(name);
            }
        }
        else
        {
           if (channel == 1)
            {
                tldlir001::Audio<int16_t> a;    
                
                tldlir001::Audio<int16_t> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<int16_t> audio2;
                audio1.load(inputFile2);

                tldlir001::Audio<int16_t> audioRangeAdd = a.RangedAdd(samplesPerSecond,audio1,audio2,range);
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_8_mono.raw";
                audioRangeAdd.save(name);

            }
            else
            {
                tldlir001::Audio<std::pair<int16_t,int16_t>> a;    
                
                tldlir001::Audio<std::pair<int16_t,int16_t>> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<std::pair<int16_t,int16_t>> audio2;
                audio1.load(inputFile2);

                tldlir001::Audio<std::pair<int16_t,int16_t>> audioRangeAdd = a.RangedAdd(samplesPerSecond,audio1,audio2,range);
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_8_stereo.raw";
                audioRangeAdd.save(name);
            }
        }
    }
    else if(strcmp(argv[9], "-cat")==0)
    {
        string inputFile1 = argv[10];
        string inputFile2 = argv[11];
        if(bitSize == 8)
        {
            if (channel == 1)
            {
                tldlir001::Audio<int8_t> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<int8_t> audio2;
                audio2.load(inputFile2);

                tldlir001::Audio<int8_t> audioCat = audio1|audio2;
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_8_mono.raw";
                audioCat.save(name);

            }
            else
            {
                tldlir001::Audio<std::pair<int8_t,int8_t>> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<std::pair<int8_t,int8_t>> audio2;
                audio2.load(inputFile2);

                tldlir001::Audio<std::pair<int8_t,int8_t>> audioCat = audio1|audio2;
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_8_stereo.raw";
                audioCat.save(name);
            }
        }
        else
        {
            if (channel == 1)
            {
                tldlir001::Audio<int16_t> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<int16_t> audio2;
                audio2.load(inputFile2);

                tldlir001::Audio<int16_t> audioCat = audio1|audio2;
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_16_mono.raw";
                audioCat.save(name);

            }
            else
            {
                tldlir001::Audio<std::pair<int16_t,int16_t>> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<std::pair<int16_t,int16_t>> audio2;
                audio2.load(inputFile2);

                tldlir001::Audio<std::pair<int16_t,int16_t>> audioCat = audio1|audio2;
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_16_stereo.raw";
                audioCat.save(name);
            }
        }
    }
    else if(strcmp(argv[9], "-v")==0)
    {
        float r1 = stof(argv[10]);
        float r2 = stof(argv[11]);
        string inputFile1 = argv[12];
        std::pair<float,float> range = make_pair(r1,r2);

        if(bitSize == 8)
        {
            if (channel == 1)
            {
                tldlir001::Audio<int8_t> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<int8_t> AudioVolume = audio1*range;
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_8_mono.raw";
                AudioVolume.save(name);
            }
            else
            {
                tldlir001::Audio<std::pair<int8_t,int8_t>> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<std::pair<int8_t,int8_t>> AudioVolume = audio1*range;
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_8_stereo.raw";
                AudioVolume.save(name);
            }
        }
        else
        {
            if (channel == 1)
            {
                tldlir001::Audio<int16_t> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<int16_t> AudioVolume = audio1*range;
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_16_mono.raw";
                AudioVolume.save(name);
            }
            else
            {
                tldlir001::Audio<std::pair<int16_t,int16_t>> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<std::pair<int16_t,int16_t>> AudioVolume = audio1*range;
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_16_stereo.raw";
                AudioVolume.save(name);
            }
        }
    }
    else if(strcmp(argv[9], "-rev")==0)
    {
        string inputFile1 = argv[10];
        if(bitSize == 8)
        {
            if (channel == 1)
            {
                tldlir001::Audio<int8_t> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<int8_t> audioRev = audio1.Reverse();
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_8_mono.raw";
                audioRev.save(name);

            }
            else
            {
                tldlir001::Audio<std::pair<int8_t,int8_t>> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<std::pair<int8_t,int8_t>> audioRev = audio1.Reverse();
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_8_stereo.raw";
                audioRev.save(name);
            }
        }
        else
        {
            if (channel == 1)
            {
                tldlir001::Audio<int16_t> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<int16_t> audioRev = audio1.Reverse();
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_16_mono.raw";
                audioRev.save(name);

            }
            else
            {
                tldlir001::Audio<std::pair<int16_t,int16_t>> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<std::pair<int16_t,int16_t>> audioRev = audio1.Reverse();
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_16_stereo.raw";
                audioRev.save(name);
            }
        }
    }
    else if(strcmp(argv[9], "-rms")==0)
    {
        string inputFile1 = argv[10];
        if(bitSize == 8)
        {
            if (channel == 1)
            {
                tldlir001::Audio<int8_t> audio1;
                audio1.load(inputFile1);

                float audioRMS = audio1.ComputeRMS();
                cout << "RMS: " << audioRMS << endl;

            }
            else
            {
                tldlir001::Audio<std::pair<int8_t,int8_t>> audio1;
                audio1.load(inputFile1);

                std::pair<float,float> audioRMS = audio1.ComputeRMS();
                cout << "channel 1 RMS: " << audioRMS.first << endl;
                cout << "channel 2 RMS: " << audioRMS.second << endl;
            }
        }
        else
        {
            if (channel == 1)
            {
                tldlir001::Audio<int16_t> audio1;
                audio1.load(inputFile1);

                float audioRMS = audio1.ComputeRMS();
                cout << "RMS: " << audioRMS << endl;

            }
            else
            {
                tldlir001::Audio<std::pair<int16_t,int16_t>> audio1;
                audio1.load(inputFile1);

                std::pair<float,float> audioRMS = audio1.ComputeRMS();
                cout << "channel 1 RMS: " << audioRMS.first << endl;
                cout << "channel 2 RMS: " << audioRMS.second << endl;
            }
        }
    }
    else if(strcmp(argv[9], "-norm")==0)
    {
        float r1 = stof(argv[10]);
        float r2 = stof(argv[11]);
        string inputFile1 = argv[12];
        std::pair<float,float> range = make_pair(r1,r2);

        if(bitSize == 8)
        {
            if (channel == 1)
            {
                tldlir001::Audio<int8_t> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<int8_t> audioNrm = audio1.Normalise(range.first);
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_8_mono.raw";
                audioNrm.save(name);

            }
            else
            {
                tldlir001::Audio<std::pair<int8_t,int8_t>> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<std::pair<int8_t,int8_t>> audioNrm = audio1.Normalise(range.first,range.second);
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_8_stereo.raw";
                audioNrm.save(name);
            }
        }
        else
        {
            if (channel == 1)
            {
                tldlir001::Audio<int16_t> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<int16_t> audioNrm = audio1.Normalise(range.first);
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_16_mono.raw";
                audioNrm.save(name);

            }
            else
            {
                tldlir001::Audio<std::pair<int16_t,int16_t>> audio1;
                audio1.load(inputFile1);

                tldlir001::Audio<std::pair<int16_t,int16_t>> audioNrm = audio1.Normalise(range.first,range.second);
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_16_stereo.raw";
                audioNrm.save(name);
            }
        }
    }
    else if(strcmp(argv[9], "-fadein")==0)
    {
        int seconds = stoi(argv[10]);
        string inputFile1 = argv[11];
        if(bitSize == 8)
        {
            if (channel == 1)
            {
                tldlir001::Audio<int8_t> audio1;
                audio1.load(inputFile1);

                //fadeSampleNo = 0.5 (arbitrary)
                tldlir001::Audio<int8_t> audioFI = audio1.FadeIn(0.5,samplesPerSecond,seconds);
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_8_mono.raw";
            }
            else
            {
                tldlir001::Audio<std::pair<int8_t,int8_t>> audio1;
                audio1.load(inputFile1);

                //fadeSampleNo = 0.5 (arbitrary)
                tldlir001::Audio<std::pair<int8_t,int8_t>> audioFI = audio1.FadeIn(0.5,samplesPerSecond,seconds);
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_8_stereo.raw";
            }
        }
        else
        {
            if (channel == 1)
            {
                tldlir001::Audio<int16_t> audio1;
                audio1.load(inputFile1);

                //fadeSampleNo = 0.5 (arbitrary)
                tldlir001::Audio<int16_t> audioFI = audio1.FadeIn(0.5,samplesPerSecond,seconds);
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_16_mono.raw";
            }
            else
            {
                tldlir001::Audio<std::pair<int16_t,int16_t>> audio1;
                audio1.load(inputFile1);

                //fadeSampleNo = 0.5 (arbitrary)
                tldlir001::Audio<std::pair<int16_t,int16_t>> audioFI = audio1.FadeIn(0.5,samplesPerSecond,seconds);
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_16_stereo.raw";
            }
        }
    }
    else if(strcmp(argv[9], "-fadeout")==0)
    {
        int seconds = stoi(argv[10]);
        string inputFile1 = argv[11];
        if(bitSize == 8)
        {
            if (channel == 1)
            {
                tldlir001::Audio<int8_t> audio1;
                audio1.load(inputFile1);

                //fadeSampleNo = 0.5 (arbitrary)
                tldlir001::Audio<int8_t> audioFI = audio1.FadeOut(0.5,samplesPerSecond,seconds);
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_8_mono.raw";
            }
            else
            {
                tldlir001::Audio<std::pair<int8_t,int8_t>> audio1;
                audio1.load(inputFile1);

                //fadeSampleNo = 0.5 (arbitrary)
                tldlir001::Audio<std::pair<int8_t,int8_t>> audioFI = audio1.FadeOut(0.5,samplesPerSecond,seconds);
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_8_stereo.raw";
            }
        }
        else
        {
            if (channel == 1)
            {
                tldlir001::Audio<int16_t> audio1;
                audio1.load(inputFile1);

                //fadeSampleNo = 0.5 (arbitrary)
                tldlir001::Audio<int16_t> audioFI = audio1.FadeOut(0.5,samplesPerSecond,seconds);
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_8_mono.raw";
            }
            else
            {
                tldlir001::Audio<std::pair<int16_t,int16_t>> audio1;
                audio1.load(inputFile1);

                //fadeSampleNo = 0.5 (arbitrary)
                tldlir001::Audio<std::pair<int16_t,int16_t>> audioFI = audio1.FadeOut(0.5,samplesPerSecond,seconds);
                string name = outputFile + "_" +  to_string(samplesPerSecond) + "_8_stereo.raw";
            }
        }
    }

    //------------------------
    //audio.load("sample_input/beez18sec_44100_signed_8bit_mono.raw"); //mono
    //audio.load("sample_input/countdown40sec_44100_signed_16bit_stereo.raw");
    //audio.save("Test1.raw");
    //-----------------------
    

    return 0;
}