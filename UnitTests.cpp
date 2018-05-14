//
// Created by liron on 2018/05/14.
//
#include "Audio.h"
#include <iostream>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

TEST_CASE("Mono Audio Copy constructor/Assignment operator","Tests functionality of the Mono Copy constructor")
{
    //8 bit:

    //constructor
    std::vector<int8_t> v = {1,2,3,4};
    tldlir001::Audio<int8_t> audio(v);
    tldlir001::Audio<int8_t> audioCopy(audio);

    for (int i = 0; i < audioCopy.data.size(); ++i)
    {
        REQUIRE(audioCopy.data[i] == audio.data[i]);
    }

    //assignment operator
    tldlir001::Audio<int8_t> audioCopy2 = audio;

    for (int i = 0; i < audioCopy2.data.size(); ++i)
    {
        REQUIRE(audioCopy2.data[i] == audio.data[i]);
    } 

    //16 bit:

    //constructor
    std::vector<int16_t> v2 = {1,2,3,4};
    tldlir001::Audio<int16_t> audio2(v2);
    tldlir001::Audio<int16_t> audioCopy3(audio2);

    for (int i = 0; i < audioCopy3.data.size(); ++i)
    {
        REQUIRE(audioCopy3.data[i] == audio.data[i]);
    }

    //assignment operator
    tldlir001::Audio<int16_t> audioCopy4 = audio2;

    for (int i = 0; i < audioCopy4.data.size(); ++i)
    {
        REQUIRE(audioCopy4.data[i] == audio.data[i]);
    } 

}

TEST_CASE("Mono Audio Move constructor","Tests functionality of the Mono Move constructor")
{
    //8 bit:

    //constructor
    std::vector<int8_t> v = {1,2,3,4};
    tldlir001::Audio<int8_t> audio(v);
    tldlir001::Audio<int8_t> audioCopy(audio); //copy of audio before its moved
    tldlir001::Audio<int8_t> audioMove(std::move(audio));

    for (int i = 0; i < audioCopy.data.size(); ++i)
    {
        REQUIRE(audioMove.data[i] == audioCopy.data[i]);
    }

     //check if old audio is deleted
    REQUIRE(audio.data.size()==0);

    //assignment operator
    tldlir001::Audio<int8_t> audioCopy2 = audioCopy;
    tldlir001::Audio<int8_t> audioMove2 = std::move(audioCopy);

    for (int i = 0; i < audioCopy2.data.size(); ++i)
    {
        REQUIRE(audioMove.data[i] == audioCopy2.data[i]);
    }

    REQUIRE(audioCopy.data.size()==0);

    //16 bit:

    //constructor
    std::vector<int16_t> v2 = {1,2,3,4};
    tldlir001::Audio<int16_t> audio2(v2);
    tldlir001::Audio<int16_t> audioCopy3(audio2); //copy of audio2 before its moved
    tldlir001::Audio<int16_t> audioMove3(std::move(audio2));

    for (int i = 0; i < audioCopy3.data.size(); ++i)
    {
        REQUIRE(audioMove3.data[i] == audioCopy3.data[i]);
    }

     //check if old audio is deleted
    REQUIRE(audio2.data.size()==0);

    //assignment operator
    tldlir001::Audio<int16_t> audioCopy4 = audioCopy3;
    tldlir001::Audio<int16_t> audioMove4 = std::move(audioCopy3);

    for (int i = 0; i < audioCopy4.data.size(); ++i)
    {
        REQUIRE(audioMove4.data[i] == audioCopy4.data[i]);
    }

    REQUIRE(audioCopy3.data.size()==0);

   
}

//NEED TO TEST MOVE AND COPY SEMANTICS FOR STEREO AS WELL!!!!!!!!!!!!!!!!



TEST_CASE("Mono Audio Concatenate operator","Tests functionality of the Mono Concatenate operator")
{
    
    //8 bit
    std::vector<int8_t> v = {1,2,3,4};
    std::vector<int8_t> v2 = {1,2,3,4};
    tldlir001::Audio<int8_t> audio(v);
    tldlir001::Audio<int8_t> audio2(v2);
    tldlir001::Audio<int8_t> audio3 = audio|audio2;

    REQUIRE(audio3.data[0] == 1);
    REQUIRE(audio3.data[1] == 2);
    REQUIRE(audio3.data[2] == 3);
    REQUIRE(audio3.data[3] == 4);
    REQUIRE(audio3.data[4] == 1);
    REQUIRE(audio3.data[5] == 2);
    REQUIRE(audio3.data[6] == 3);
    REQUIRE(audio3.data[7] == 4);

    //16 bit
    std::vector<int16_t> v3 = {1,2,3,4};
    std::vector<int16_t> v4 = {1,2,3,4};
    tldlir001::Audio<int16_t> audio4(v3);
    tldlir001::Audio<int16_t> audio5(v4);
    tldlir001::Audio<int16_t> audio6 = audio4|audio5;

    REQUIRE(audio6.data[0] == 1);
    REQUIRE(audio6.data[1] == 2);
    REQUIRE(audio6.data[2] == 3);
    REQUIRE(audio6.data[3] == 4);
    REQUIRE(audio6.data[4] == 1);
    REQUIRE(audio6.data[5] == 2);
    REQUIRE(audio6.data[6] == 3);
    REQUIRE(audio6.data[7] == 4);
}

TEST_CASE("Stereo Audio Concatenate operator","Tests functionality of the Stereo Concatenate operator")
{
    
    //8 bit
    std::vector<pair<int8_t,int8_t>> v = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    std::vector<pair<int8_t,int8_t>> v2 = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    tldlir001::Audio<pair<int8_t,int8_t>> audio(v);
    tldlir001::Audio<pair<int8_t,int8_t>> audio2(v2);
    tldlir001::Audio<pair<int8_t,int8_t>> audio3 = audio|audio2;

    REQUIRE(audio3.data[0].first == 1);
    REQUIRE(audio3.data[0].second == 1);
    REQUIRE(audio3.data[1].first == 2);
    REQUIRE(audio3.data[1].second == 2);
    REQUIRE(audio3.data[2].first == 3);
    REQUIRE(audio3.data[2].second == 3);
    REQUIRE(audio3.data[3].first == 4);
    REQUIRE(audio3.data[3].second == 4);
    REQUIRE(audio3.data[4].first == 1);
    REQUIRE(audio3.data[4].second == 1);
    REQUIRE(audio3.data[5].first == 2);
    REQUIRE(audio3.data[5].second == 2);
    REQUIRE(audio3.data[6].first == 3);
    REQUIRE(audio3.data[6].second == 3);
    REQUIRE(audio3.data[7].first == 4);
    REQUIRE(audio3.data[7].second == 4);

    //16 bit
    std::vector<pair<int16_t,int16_t>> v3 = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    std::vector<pair<int16_t,int16_t>> v4 = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    tldlir001::Audio<pair<int16_t,int16_t>> audio4(v3);
    tldlir001::Audio<pair<int16_t,int16_t>> audio5(v4);
    tldlir001::Audio<pair<int16_t,int16_t>> audio6 = audio4|audio5;

    REQUIRE(audio6.data[0].first == 1);
    REQUIRE(audio6.data[0].second == 1);
    REQUIRE(audio6.data[1].first == 2);
    REQUIRE(audio6.data[1].second == 2);
    REQUIRE(audio6.data[2].first == 3);
    REQUIRE(audio6.data[2].second == 3);
    REQUIRE(audio6.data[3].first == 4);
    REQUIRE(audio6.data[3].second == 4);
    REQUIRE(audio6.data[4].first == 1);
    REQUIRE(audio6.data[4].second == 1);
    REQUIRE(audio6.data[5].first == 2);
    REQUIRE(audio6.data[5].second == 2);
    REQUIRE(audio6.data[6].first == 3);
    REQUIRE(audio6.data[6].second == 3);
    REQUIRE(audio6.data[7].first == 4);
    REQUIRE(audio6.data[7].second == 4);
   
}


TEST_CASE("Mono Audio Volume operator","Tests functionality of the Mono Volume operator")
{
    //8 bit
    std::vector<int8_t> v = {1,2,3,4};
    std::pair<float,float> p = make_pair(0.5,0.5);
    tldlir001::Audio<int8_t> audio(v);
    tldlir001::Audio<int8_t> audio2 = audio*p;

    REQUIRE(audio2.data[0] == 0);
    REQUIRE(audio2.data[1] == 1);
    REQUIRE(audio2.data[2] == 1);
    REQUIRE(audio2.data[3] == 2);

    //16 bit
    std::vector<int16_t> v2 = {1,2,3,4};
    std::pair<float,float> p2 = make_pair(0.5,0.5);
    tldlir001::Audio<int16_t> audio3(v2);
    tldlir001::Audio<int16_t> audio4 = audio3*p2;

    REQUIRE(audio4.data[0] == 0);
    REQUIRE(audio4.data[1] == 1);
    REQUIRE(audio4.data[2] == 1);
    REQUIRE(audio4.data[3] == 2);

}

TEST_CASE("Stereo Audio Volume operator","Tests functionality of the Stereo Volume operator")
{
    //8 bit
    std::vector<pair<int8_t,int8_t>> v = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    std::pair<float,float> p = make_pair(0.5,0.5);
    tldlir001::Audio<pair<int8_t,int8_t>> audio(v);
    tldlir001::Audio<pair<int8_t,int8_t>> audio2 = audio*p;

    REQUIRE(audio2.data[0].first == 0);
    REQUIRE(audio2.data[0].second == 0);
    REQUIRE(audio2.data[1].first == 1);
    REQUIRE(audio2.data[1].second == 1);
    REQUIRE(audio2.data[2].first == 1);
    REQUIRE(audio2.data[2].second == 1);
    REQUIRE(audio2.data[3].first == 2);
    REQUIRE(audio2.data[3].second == 2);

    //16 bit
    std::vector<pair<int16_t,int16_t>> v2 = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    std::pair<float,float> p2 = make_pair(0.5,0.5);
    tldlir001::Audio<pair<int16_t,int16_t>> audio3(v2);
    tldlir001::Audio<pair<int16_t,int16_t>> audio4 = audio3*p2;

    REQUIRE(audio4.data[0].first == 0);
    REQUIRE(audio4.data[0].second == 0);
    REQUIRE(audio4.data[1].first == 1);
    REQUIRE(audio4.data[1].second == 1);
    REQUIRE(audio4.data[2].first == 1);
    REQUIRE(audio4.data[2].second == 1);
    REQUIRE(audio4.data[3].first == 2);
    REQUIRE(audio4.data[3].second == 2);

}


TEST_CASE("Mono Audio Add operator","Tests functionality of the Mono Add operator")
{
    //8 bit
    std::vector<int8_t> v = {1,2,3,4};
    std::vector<int8_t> v2 = {1,2,3,4};
    tldlir001::Audio<int8_t> audio(v);
    tldlir001::Audio<int8_t> audio2(v2);
    tldlir001::Audio<int8_t> audio3 = audio+audio2;
    for (int i = 0; i < audio3.data.size(); ++i)
    {
        REQUIRE(audio3.data[i] == audio.data[i] + audio2.data[i]);
    }

    //16 bit
    std::vector<int16_t> v3 = {1,2,3,4};
    std::vector<int16_t> v4 = {1,2,3,4};
    tldlir001::Audio<int16_t> audio4(v3);
    tldlir001::Audio<int16_t> audio5(v4);
    tldlir001::Audio<int16_t> audio6 = audio4+audio5;
    for (int i = 0; i < audio6.data.size(); ++i)
    {
        REQUIRE(audio6.data[i] == audio4.data[i] + audio5.data[i]);
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
    for (int i = 0; i < audio3.data.size(); ++i)
    {
        int a1 = audio3.data[i].first;
        int a2 = audio3.data[i].second;

        int f = audio.data[i].first + audio2.data[i].first;
        int s = audio.data[i].second + audio2.data[i].second;

        REQUIRE(a1 == f);
        REQUIRE(a2 == s);
    }

    //16 bit
    std::vector<pair<int16_t,int16_t>> v3 = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    std::vector<pair<int16_t,int16_t>> v4 = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    tldlir001::Audio<pair<int16_t,int16_t>> audio4(v3);
    tldlir001::Audio<pair<int16_t,int16_t>> audio5(v4);
    tldlir001::Audio<pair<int16_t,int16_t>> audio6 = audio4+audio5; //this line works fine (weird clion problem)
    for (int i = 0; i < audio3.data.size(); ++i)
    {
        int a1 = audio6.data[i].first;
        int a2 = audio6.data[i].second;

        int f = audio4.data[i].first + audio5.data[i].first;
        int s = audio4.data[i].second + audio5.data[i].second;

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

    REQUIRE(audio2.data[0]==1);
    REQUIRE(audio2.data[1]==4);

    //16 bit:
    std::vector<int16_t> v2 = {1,2,3,4};
    std::pair<int,int> p2 = make_pair(1,3);
    tldlir001::Audio<int16_t> audio3(v2);
    tldlir001::Audio<int16_t> audio4 = audio3^p2;

    REQUIRE(audio4.data[0]==1);
    REQUIRE(audio4.data[1]==4);
}

TEST_CASE("Stereo Audio Cut operator","Tests functionality of the Stereo Cut operator")
{
    //8 bit:

    std::vector<pair<int8_t,int8_t>> v = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    std::pair<int,int> p = make_pair(1,3);
    tldlir001::Audio<pair<int8_t,int8_t>> audio(v);
    tldlir001::Audio<pair<int8_t,int8_t>> audio2 = audio^p;

    REQUIRE(audio2.data[0].first==1);
    REQUIRE(audio2.data[0].second==1);
    REQUIRE(audio2.data[1].first==4);
    REQUIRE(audio2.data[1].second==4);

    //16 bit:

    std::vector<pair<int16_t,int16_t>> v2 = {make_pair(1,1),make_pair(2,2),make_pair(3,3),make_pair(4,4)};
    std::pair<int,int> p2 = make_pair(1,3);
    tldlir001::Audio<pair<int16_t,int16_t>> audio3(v2);
    tldlir001::Audio<pair<int16_t,int16_t>> audio4 = audio3^p;

    REQUIRE(audio4.data[0].first==1);
    REQUIRE(audio4.data[0].second==1);
    REQUIRE(audio4.data[1].first==4);
    REQUIRE(audio4.data[1].second==4);

}