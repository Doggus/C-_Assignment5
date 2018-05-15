//
// Created by liron on 2018/05/14.
//
#include "Audio.h"
#include <iostream>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

TEST_CASE("Mono Audio Copy constructor/Assignment operator","Tests functionality of the Mono Copy constructor and Assignment Operator")
{
    //8 bit:

    //constructor
    std::vector<int8_t> v = {1,2,3,4};
    tldlir001::Audio<int8_t> audio(v);
    tldlir001::Audio<int8_t> audioCopy(audio);

    for (int i = 0; i < audioCopy.getData().size(); ++i)
    {
        REQUIRE(audioCopy.getData()[i] == audio.getData()[i]);
    }

    //assignment operator
    tldlir001::Audio<int8_t> audioCopy2 = audio;

    for (int i = 0; i < audioCopy2.getData().size(); ++i)
    {
        REQUIRE(audioCopy2.getData()[i] == audio.getData()[i]);
    } 

    //16 bit:

    //constructor
    std::vector<int16_t> v2 = {1,2,3,4};
    tldlir001::Audio<int16_t> audio2(v2);
    tldlir001::Audio<int16_t> audioCopy3(audio2);

    for (int i = 0; i < audioCopy3.getData().size(); ++i)
    {
        REQUIRE(audioCopy3.getData()[i] == audio.getData()[i]);
    }

    //assignment operator
    tldlir001::Audio<int16_t> audioCopy4 = audio2;

    for (int i = 0; i < audioCopy4.getData().size(); ++i)
    {
        REQUIRE(audioCopy4.getData()[i] == audio.getData()[i]);
    } 

}

TEST_CASE("Mono Audio Move constructor/Assignment Operator","Tests functionality of the Mono Move constructor and Assignment Operator")
{
    //8 bit:

    //constructor
    std::vector<int8_t> v = {1,2,3,4};
    tldlir001::Audio<int8_t> audio(v);
    tldlir001::Audio<int8_t> audioCopy(audio); //copy of audio before its moved
    tldlir001::Audio<int8_t> audioMove(std::move(audio));

    for (int i = 0; i < audioCopy.getData().size(); ++i)
    {
        REQUIRE(audioMove.getData()[i] == audioCopy.getData()[i]);
    }

     //check if old audio is deleted
    REQUIRE(audio.getData().size()==0);

    //assignment operator
    tldlir001::Audio<int8_t> audioCopy2 = audioCopy;
    tldlir001::Audio<int8_t> audioMove2 = std::move(audioCopy);

    for (int i = 0; i < audioCopy2.getData().size(); ++i)
    {
        REQUIRE(audioMove.getData()[i] == audioCopy2.getData()[i]);
    }

    REQUIRE(audioCopy.getData().size()==0);

    //16 bit:

    //constructor
    std::vector<int16_t> v2 = {1,2,3,4};
    tldlir001::Audio<int16_t> audio2(v2);
    tldlir001::Audio<int16_t> audioCopy3(audio2); //copy of audio2 before its moved
    tldlir001::Audio<int16_t> audioMove3(std::move(audio2));

    for (int i = 0; i < audioCopy3.getData().size(); ++i)
    {
        REQUIRE(audioMove3.getData()[i] == audioCopy3.getData()[i]);
    }

     //check if old audio is deleted
    REQUIRE(audio2.getData().size()==0);

    //assignment operator
    tldlir001::Audio<int16_t> audioCopy4 = audioCopy3;
    tldlir001::Audio<int16_t> audioMove4 = std::move(audioCopy3);

    for (int i = 0; i < audioCopy4.getData().size(); ++i)
    {
        REQUIRE(audioMove4.getData()[i] == audioCopy4.getData()[i]);
    }

    REQUIRE(audioCopy3.getData().size()==0);

   
}

//NEED TO TEST MOVE AND COPY SEMANTICS FOR STEREO AS WELL!!!!!!!!!!!!!!!!
TEST_CASE("Stereo Audio Copy constructor/Assignment Operator","Tests functionality of the Stereo Copy constructor and assignment operator")
{
    //8 bit:

    //constructor
    std::vector<pair<int8_t,int8_t>> v = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    tldlir001::Audio<pair<int8_t,int8_t>> audio(v);
    tldlir001::Audio<pair<int8_t,int8_t>> audioCopy(audio);

    for (int i = 0; i < audioCopy.getData().size(); ++i)
    {
        REQUIRE(audioCopy.getData()[i].first == audio.getData()[i].first);
        REQUIRE(audioCopy.getData()[i].second == audio.getData()[i].second);
    }

    //assignment operator
    tldlir001::Audio<pair<int8_t,int8_t>> audioCopy2 = audio;

    for (int i = 0; i < audioCopy2.getData().size(); ++i)
    {
        REQUIRE(audioCopy2.getData()[i].first == audio.getData()[i].first);
        REQUIRE(audioCopy2.getData()[i].second == audio.getData()[i].second);
    } 

    //16 bit:

    //constructor
    std::vector<pair<int16_t,int16_t>> v2 = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    tldlir001::Audio<pair<int16_t,int16_t>> audio2(v2);
    tldlir001::Audio<pair<int16_t,int16_t>> audioCopy3(audio2);

    for (int i = 0; i < audioCopy3.getData().size(); ++i)
    {
        REQUIRE(audioCopy3.getData()[i].first == audio.getData()[i].first);
        REQUIRE(audioCopy3.getData()[i].second == audio.getData()[i].second);
    }

    //assignment operator
    tldlir001::Audio<pair<int16_t,int16_t>> audioCopy4 = audio2;

    for (int i = 0; i < audioCopy4.getData().size(); ++i)
    {
        REQUIRE(audioCopy4.getData()[i].first == audio.getData()[i].first);
        REQUIRE(audioCopy4.getData()[i].second == audio.getData()[i].second);
    } 
}

TEST_CASE("Stereo Audio Move constructor/Assignment Operator","Tests functionality of the Stereo Move constructor and Assignment Operator")
{
    //8 bit:

    //constructor
    std::vector<pair<int8_t,int8_t>> v = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    tldlir001::Audio<pair<int8_t,int8_t>> audio(v);
    tldlir001::Audio<pair<int8_t,int8_t>> audioCopy(audio); //copy of audio before its moved
    tldlir001::Audio<pair<int8_t,int8_t>> audioMove(std::move(audio));

    for (int i = 0; i < audioCopy.getData().size(); ++i)
    {
        REQUIRE(audioMove.getData()[i].first == audioCopy.getData()[i].first);
        REQUIRE(audioMove.getData()[i].second == audioCopy.getData()[i].second);
    }

     //check if old audio is deleted
    REQUIRE(audio.getData().size()==0);

    //assignment operator
    tldlir001::Audio<pair<int8_t,int8_t>> audioCopy2 = audioCopy;
    tldlir001::Audio<pair<int8_t,int8_t>> audioMove2 = std::move(audioCopy);

    for (int i = 0; i < audioCopy2.getData().size(); ++i)
    {
        REQUIRE(audioMove.getData()[i].first == audioCopy2.getData()[i].first);
        REQUIRE(audioMove.getData()[i].second == audioCopy2.getData()[i].second);
    }

    REQUIRE(audioCopy.getData().size()==0);

    //16 bit:

    //constructor
    std::vector<pair<int16_t,int16_t>> v2 = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    tldlir001::Audio<pair<int16_t,int16_t>> audio2(v2);
    tldlir001::Audio<pair<int16_t,int16_t>> audioCopy3(audio2); //copy of audio2 before its moved
    tldlir001::Audio<pair<int16_t,int16_t>> audioMove3(std::move(audio2));

    for (int i = 0; i < audioCopy3.getData().size(); ++i)
    {
        REQUIRE(audioMove3.getData()[i].first == audioCopy3.getData()[i].first);
        REQUIRE(audioMove3.getData()[i].second == audioCopy3.getData()[i].second);
    }

     //check if old audio is deleted
    REQUIRE(audio2.getData().size()==0);

    //assignment operator
    tldlir001::Audio<pair<int16_t,int16_t>> audioCopy4 = audioCopy3;
    tldlir001::Audio<pair<int16_t,int16_t>> audioMove4 = std::move(audioCopy3);

    for (int i = 0; i < audioCopy4.getData().size(); ++i)
    {
        REQUIRE(audioMove4.getData()[i].first == audioCopy4.getData()[i].first);
        REQUIRE(audioMove4.getData()[i].second == audioCopy4.getData()[i].second);
    }

    REQUIRE(audioCopy3.getData().size()==0);

}


TEST_CASE("Mono Audio Concatenate operator","Tests functionality of the Mono Concatenate operator")
{
    
    //8 bit
    std::vector<int8_t> v = {1,2,3,4};
    std::vector<int8_t> v2 = {1,2,3,4};
    tldlir001::Audio<int8_t> audio(v);
    tldlir001::Audio<int8_t> audio2(v2);
    tldlir001::Audio<int8_t> audio3 = audio|audio2;

    REQUIRE(audio3.getData()[0] == 1);
    REQUIRE(audio3.getData()[1] == 2);
    REQUIRE(audio3.getData()[2] == 3);
    REQUIRE(audio3.getData()[3] == 4);
    REQUIRE(audio3.getData()[4] == 1);
    REQUIRE(audio3.getData()[5] == 2);
    REQUIRE(audio3.getData()[6] == 3);
    REQUIRE(audio3.getData()[7] == 4);

    //16 bit
    std::vector<int16_t> v3 = {1,2,3,4};
    std::vector<int16_t> v4 = {1,2,3,4};
    tldlir001::Audio<int16_t> audio4(v3);
    tldlir001::Audio<int16_t> audio5(v4);
    tldlir001::Audio<int16_t> audio6 = audio4|audio5;

    REQUIRE(audio6.getData()[0] == 1);
    REQUIRE(audio6.getData()[1] == 2);
    REQUIRE(audio6.getData()[2] == 3);
    REQUIRE(audio6.getData()[3] == 4);
    REQUIRE(audio6.getData()[4] == 1);
    REQUIRE(audio6.getData()[5] == 2);
    REQUIRE(audio6.getData()[6] == 3);
    REQUIRE(audio6.getData()[7] == 4);
}

TEST_CASE("Stereo Audio Concatenate operator","Tests functionality of the Stereo Concatenate operator")
{
    
    //8 bit
    std::vector<pair<int8_t,int8_t>> v = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    std::vector<pair<int8_t,int8_t>> v2 = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    tldlir001::Audio<pair<int8_t,int8_t>> audio(v);
    tldlir001::Audio<pair<int8_t,int8_t>> audio2(v2);
    tldlir001::Audio<pair<int8_t,int8_t>> audio3 = audio|audio2;

    REQUIRE(audio3.getData()[0].first == 1);
    REQUIRE(audio3.getData()[0].second == 1);
    REQUIRE(audio3.getData()[1].first == 2);
    REQUIRE(audio3.getData()[1].second == 2);
    REQUIRE(audio3.getData()[2].first == 3);
    REQUIRE(audio3.getData()[2].second == 3);
    REQUIRE(audio3.getData()[3].first == 4);
    REQUIRE(audio3.getData()[3].second == 4);
    REQUIRE(audio3.getData()[4].first == 1);
    REQUIRE(audio3.getData()[4].second == 1);
    REQUIRE(audio3.getData()[5].first == 2);
    REQUIRE(audio3.getData()[5].second == 2);
    REQUIRE(audio3.getData()[6].first == 3);
    REQUIRE(audio3.getData()[6].second == 3);
    REQUIRE(audio3.getData()[7].first == 4);
    REQUIRE(audio3.getData()[7].second == 4);

    //16 bit
    std::vector<pair<int16_t,int16_t>> v3 = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    std::vector<pair<int16_t,int16_t>> v4 = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    tldlir001::Audio<pair<int16_t,int16_t>> audio4(v3);
    tldlir001::Audio<pair<int16_t,int16_t>> audio5(v4);
    tldlir001::Audio<pair<int16_t,int16_t>> audio6 = audio4|audio5;

    REQUIRE(audio6.getData()[0].first == 1);
    REQUIRE(audio6.getData()[0].second == 1);
    REQUIRE(audio6.getData()[1].first == 2);
    REQUIRE(audio6.getData()[1].second == 2);
    REQUIRE(audio6.getData()[2].first == 3);
    REQUIRE(audio6.getData()[2].second == 3);
    REQUIRE(audio6.getData()[3].first == 4);
    REQUIRE(audio6.getData()[3].second == 4);
    REQUIRE(audio6.getData()[4].first == 1);
    REQUIRE(audio6.getData()[4].second == 1);
    REQUIRE(audio6.getData()[5].first == 2);
    REQUIRE(audio6.getData()[5].second == 2);
    REQUIRE(audio6.getData()[6].first == 3);
    REQUIRE(audio6.getData()[6].second == 3);
    REQUIRE(audio6.getData()[7].first == 4);
    REQUIRE(audio6.getData()[7].second == 4);
   
}


TEST_CASE("Mono Audio Volume operator","Tests functionality of the Mono Volume operator")
{
    //8 bit
    std::vector<int8_t> v = {1,2,3,4};
    std::pair<float,float> p = make_pair(0.5,0.5);
    tldlir001::Audio<int8_t> audio(v);
    tldlir001::Audio<int8_t> audio2 = audio*p;

    REQUIRE(audio2.getData()[0] == 0);
    REQUIRE(audio2.getData()[1] == 1);
    REQUIRE(audio2.getData()[2] == 1);
    REQUIRE(audio2.getData()[3] == 2);

    //16 bit
    std::vector<int16_t> v2 = {1,2,3,4};
    std::pair<float,float> p2 = make_pair(0.5,0.5);
    tldlir001::Audio<int16_t> audio3(v2);
    tldlir001::Audio<int16_t> audio4 = audio3*p2;

    REQUIRE(audio4.getData()[0] == 0);
    REQUIRE(audio4.getData()[1] == 1);
    REQUIRE(audio4.getData()[2] == 1);
    REQUIRE(audio4.getData()[3] == 2);

}

TEST_CASE("Stereo Audio Volume operator","Tests functionality of the Stereo Volume operator")
{
    //8 bit
    std::vector<pair<int8_t,int8_t>> v = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    std::pair<float,float> p = make_pair(0.5,0.5);
    tldlir001::Audio<pair<int8_t,int8_t>> audio(v);
    tldlir001::Audio<pair<int8_t,int8_t>> audio2 = audio*p;

    REQUIRE(audio2.getData()[0].first == 0);
    REQUIRE(audio2.getData()[0].second == 0);
    REQUIRE(audio2.getData()[1].first == 1);
    REQUIRE(audio2.getData()[1].second == 1);
    REQUIRE(audio2.getData()[2].first == 1);
    REQUIRE(audio2.getData()[2].second == 1);
    REQUIRE(audio2.getData()[3].first == 2);
    REQUIRE(audio2.getData()[3].second == 2);

    //16 bit
    std::vector<pair<int16_t,int16_t>> v2 = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    std::pair<float,float> p2 = make_pair(0.5,0.5);
    tldlir001::Audio<pair<int16_t,int16_t>> audio3(v2);
    tldlir001::Audio<pair<int16_t,int16_t>> audio4 = audio3*p2;

    REQUIRE(audio4.getData()[0].first == 0);
    REQUIRE(audio4.getData()[0].second == 0);
    REQUIRE(audio4.getData()[1].first == 1);
    REQUIRE(audio4.getData()[1].second == 1);
    REQUIRE(audio4.getData()[2].first == 1);
    REQUIRE(audio4.getData()[2].second == 1);
    REQUIRE(audio4.getData()[3].first == 2);
    REQUIRE(audio4.getData()[3].second == 2);

}


TEST_CASE("Mono Audio Add operator","Tests functionality of the Mono Add operator")
{
    //8 bit
    std::vector<int8_t> v = {1,2,3,4};
    std::vector<int8_t> v2 = {1,2,3,4};
    tldlir001::Audio<int8_t> audio(v);
    tldlir001::Audio<int8_t> audio2(v2);
    tldlir001::Audio<int8_t> audio3 = audio+audio2;
    for (int i = 0; i < audio3.getData().size(); ++i)
    {
        REQUIRE(audio3.getData()[i] == audio.getData()[i] + audio2.getData()[i]);
    }

    //16 bit
    std::vector<int16_t> v3 = {1,2,3,4};
    std::vector<int16_t> v4 = {1,2,3,4};
    tldlir001::Audio<int16_t> audio4(v3);
    tldlir001::Audio<int16_t> audio5(v4);
    tldlir001::Audio<int16_t> audio6 = audio4+audio5;
    for (int i = 0; i < audio6.getData().size(); ++i)
    {
        REQUIRE(audio6.getData()[i] == audio4.getData()[i] + audio5.getData()[i]);
    }
}

TEST_CASE("Stereo Audio Add operator","Tests functionality of the Stereo Add operator")
{
    //8 bit
    std::vector<pair<int8_t,int8_t>> v = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    std::vector<pair<int8_t,int8_t>> v2 = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    tldlir001::Audio<pair<int8_t,int8_t>> audio(v);
    tldlir001::Audio<pair<int8_t,int8_t>> audio2(v2);
    tldlir001::Audio<pair<int8_t,int8_t>> audio3 = audio+audio2; //this line works fine (weird clion problem)
    for (int i = 0; i < audio3.getData().size(); ++i)
    {
        int a1 = audio3.getData()[i].first;
        int a2 = audio3.getData()[i].second;

        int f = audio.getData()[i].first + audio2.getData()[i].first;
        int s = audio.getData()[i].second + audio2.getData()[i].second;

        REQUIRE(a1 == f);
        REQUIRE(a2 == s);
    }

    //16 bit
    std::vector<pair<int16_t,int16_t>> v3 = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    std::vector<pair<int16_t,int16_t>> v4 = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    tldlir001::Audio<pair<int16_t,int16_t>> audio4(v3);
    tldlir001::Audio<pair<int16_t,int16_t>> audio5(v4);
    tldlir001::Audio<pair<int16_t,int16_t>> audio6 = audio4+audio5; //this line works fine (weird clion problem)
    for (int i = 0; i < audio3.getData().size(); ++i)
    {
        int a1 = audio6.getData()[i].first;
        int a2 = audio6.getData()[i].second;

        int f = audio4.getData()[i].first + audio5.getData()[i].first;
        int s = audio4.getData()[i].second + audio5.getData()[i].second;

        REQUIRE(a1 == f);
        REQUIRE(a2 == s);
    }

}

TEST_CASE("Mono Audio Cut operator","Tests functionality of the Mono Cut operator")
{
    //8 bit:

    std::vector<int8_t> v = {1,2,3,4};
    std::pair<int,int> p = make_pair(1,3);
    tldlir001::Audio<int8_t> audio(v);
    tldlir001::Audio<int8_t> audio2 = audio^p;

    REQUIRE(audio2.getData()[0]==1);
    REQUIRE(audio2.getData()[1]==4);

    //16 bit:
    std::vector<int16_t> v2 = {1,2,3,4};
    std::pair<int,int> p2 = make_pair(1,3);
    tldlir001::Audio<int16_t> audio3(v2);
    tldlir001::Audio<int16_t> audio4 = audio3^p2;

    REQUIRE(audio4.getData()[0]==1);
    REQUIRE(audio4.getData()[1]==4);
}

TEST_CASE("Stereo Audio Cut operator","Tests functionality of the Stereo Cut operator")
{
    //8 bit:

    std::vector<pair<int8_t,int8_t>> v = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    std::pair<int,int> p = make_pair(1,3);
    tldlir001::Audio<pair<int8_t,int8_t>> audio(v);
    tldlir001::Audio<pair<int8_t,int8_t>> audio2 = audio^p;

    REQUIRE(audio2.getData()[0].first==1);
    REQUIRE(audio2.getData()[0].second==1);
    REQUIRE(audio2.getData()[1].first==4);
    REQUIRE(audio2.getData()[1].second==4);

    //16 bit:

    std::vector<pair<int16_t,int16_t>> v2 = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    std::pair<int,int> p2 = make_pair(1,3);
    tldlir001::Audio<pair<int16_t,int16_t>> audio3(v2);
    tldlir001::Audio<pair<int16_t,int16_t>> audio4 = audio3^p;

    REQUIRE(audio4.getData()[0].first==1);
    REQUIRE(audio4.getData()[0].second==1);
    REQUIRE(audio4.getData()[1].first==4);
    REQUIRE(audio4.getData()[1].second==4);

}

TEST_CASE("Mono Audio Reverse method","Tests functionality of the Mono Reverse method")
{
    //8 bit

    std::vector<int8_t> v = {1,2,3,4};
    tldlir001::Audio<int8_t> audio(v);
    tldlir001::Audio<int8_t> audio2 = audio.Reverse();

    REQUIRE(audio2.getData()[0] == 4);
    REQUIRE(audio2.getData()[1] == 3);
    REQUIRE(audio2.getData()[2] == 2);
    REQUIRE(audio2.getData()[3] == 1);

    //16 bit

    std::vector<int16_t> v2 = {1,2,3,4};
    tldlir001::Audio<int16_t> audio3(v2);
    tldlir001::Audio<int16_t> audio4 = audio3.Reverse();

    REQUIRE(audio4.getData()[0] == 4);
    REQUIRE(audio4.getData()[1] == 3);
    REQUIRE(audio4.getData()[2] == 2);
    REQUIRE(audio4.getData()[3] == 1);
}

TEST_CASE("Stereo Audio Reverse method","Tests functionality of the Stereo Reverse method")
{
    //8 bit

    std::vector<pair<int8_t,int8_t>> v = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    tldlir001::Audio<pair<int8_t,int8_t>> audio(v);
    tldlir001::Audio<pair<int8_t,int8_t>> audio2 = audio.Reverse();

    REQUIRE(audio2.getData()[0].first == 4);
    REQUIRE(audio2.getData()[0].second == 4);
    REQUIRE(audio2.getData()[1].first == 3);
    REQUIRE(audio2.getData()[1].second == 3);
    REQUIRE(audio2.getData()[2].first == 2);
    REQUIRE(audio2.getData()[2].second == 2);
    REQUIRE(audio2.getData()[3].first == 1);
    REQUIRE(audio2.getData()[3].second == 1);

    //16 bit

    std::vector<pair<int16_t,int16_t>> v2 = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    tldlir001::Audio<pair<int16_t,int16_t>> audio3(v2);
    tldlir001::Audio<pair<int16_t,int16_t>> audio4 = audio3.Reverse();

    REQUIRE(audio4.getData()[0].first == 4);
    REQUIRE(audio4.getData()[0].second == 4);
    REQUIRE(audio4.getData()[1].first == 3);
    REQUIRE(audio4.getData()[1].second == 3);
    REQUIRE(audio4.getData()[2].first == 2);
    REQUIRE(audio4.getData()[2].second == 2);
    REQUIRE(audio4.getData()[3].first == 1);
    REQUIRE(audio4.getData()[3].second == 1);

}


TEST_CASE("Mono Audio Ranged Add method","Tests functionality of the Mono Ranged Add method")
{
    //8 bit

    std::vector<int8_t> v = {1,2,3,4,5,6,7};
    tldlir001::Audio<int8_t> audio(v);
    tldlir001::Audio<int8_t> audio1(v);
    std::pair<int8_t,int8_t> p = make_pair(2,5);
    tldlir001::Audio<int8_t> audio2 = audio.RangedAdd(1,audio,audio1,p);

    REQUIRE(audio2.getData()[0] == 6);
    REQUIRE(audio2.getData()[1] == 8);
    REQUIRE(audio2.getData()[2] == 10);


    //16 bit

    std::vector<int16_t> v2 = {1,2,3,4,5,6,7};
    tldlir001::Audio<int16_t> audio3(v2);
    tldlir001::Audio<int16_t> audio4(v2);
    std::pair<int16_t,int16_t> p2 = make_pair(2,5);
    tldlir001::Audio<int16_t> audio5 = audio3.RangedAdd(1,audio3,audio4,p);

    REQUIRE(audio2.getData()[0] == 6);
    REQUIRE(audio2.getData()[1] == 8);
    REQUIRE(audio2.getData()[2] == 10);

}

TEST_CASE("Stereo Audio Ranged Add method","Tests functionality of the Stereo Ranged Add method")
{
    //8 bit

    std::vector<pair<int8_t,int8_t>> v = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4),make_pair(5,5),make_pair(6,6),make_pair(7,7)};
    tldlir001::Audio<pair<int8_t,int8_t>> audio(v);
    tldlir001::Audio<pair<int8_t,int8_t>> audio1(v);
    std::pair<int8_t,int8_t> p = make_pair(2,5);
    tldlir001::Audio<pair<int8_t,int8_t>> audio2 = audio.RangedAdd(1,audio,audio1,p);

    REQUIRE(audio2.getData()[0].first == 6);
    REQUIRE(audio2.getData()[0].second == 6);
    REQUIRE(audio2.getData()[1].first == 8);
    REQUIRE(audio2.getData()[1].second == 8);
    REQUIRE(audio2.getData()[2].first == 10);
    REQUIRE(audio2.getData()[2].second == 10);


    //16 bit

    std::vector<pair<int16_t,int16_t>> v2 = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4),make_pair(5,5),make_pair(6,6),make_pair(7,7)};
    tldlir001::Audio<pair<int16_t,int16_t>> audio3(v2);
    tldlir001::Audio<pair<int16_t,int16_t>> audio4(v2);
    std::pair<int16_t,int16_t> p2 = make_pair(2,5);
    tldlir001::Audio<pair<int16_t,int16_t>> audio5 = audio3.RangedAdd(1,audio3,audio4,p);

    REQUIRE(audio5.getData()[0].first == 6);
    REQUIRE(audio5.getData()[0].second == 6);
    REQUIRE(audio5.getData()[1].first == 8);
    REQUIRE(audio5.getData()[1].second == 8);
    REQUIRE(audio5.getData()[2].first == 10);
    REQUIRE(audio5.getData()[2].second == 10);

}

//TESTS:
   

    //float rms = audio.ComputeRMS();
    //cout << rms << endl;