#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    string s { "Hello   World   Tour  " };
    
    // To lower
    string s2{s};
    transform(s2.begin(), s2.end(), s2.begin(), [](unsigned char c){return tolower(c);});
    cout << s2 << endl;

    // Split
    string delimiter = " ";
    string s3{s};
    string token;
    size_t pos = 0;
    vector<string> result;
    while((pos = s3.find(delimiter)) != string::npos)
    {
        token = s3.substr(0, pos);
        if(token.length() != 0)
        {
            result.push_back(token);
        }
        s3.erase(0, pos + delimiter.length());
    }
    if(s3.length() != 0)
    {    
        result.push_back(s3);
    }    
    for(auto word : result)
    {
        cout << word << ", ";
    }
    cout << endl;

    return 0;
}