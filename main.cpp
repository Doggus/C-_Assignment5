#include "Audio.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::cout << "Hello, World!" << std::endl;
    std::vector<int> v = {1,2,3,4};
    cout<< v[0] << endl;
    std::vector<int> v2 = {1,2,3,4};
    cout<< v2[0] << endl;

    tldlir001::Audio<int> audio(v);

    tldlir001::Audio<int> audio2(v2);

    tldlir001::Audio<int> audio3 = audio+audio2;


    for (int i = 0; i < audio3.data.size(); ++i)
    {
        cout << audio3.data[i] << endl;
    }
     

    return 0;
}