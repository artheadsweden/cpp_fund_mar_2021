#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class String
{
public:
    String(const string& cs) : s{cs} {}
    
    String to_lower()
    {
        string temp_str{s};
        transform(temp_str.begin(), temp_str.end(), temp_str.begin(), [](unsigned char c){return tolower(c);});
        return {temp_str};
    }
    
    vector<string> split(const string& delimiter = " ")
    {
        string temp_str{s};
        string token;
        size_t pos = 0;
        vector<string> result;
        while((pos = temp_str.find(delimiter)) != string::npos)
        {
            token = temp_str.substr(0, pos);
            if(token.length() != 0)
            {
                result.push_back(token);
            }
            temp_str.erase(0, pos + delimiter.length());
        }
        if(temp_str.length() != 0)
        {    
            result.push_back(temp_str);
        }   
        return result;
    }

private:  
    string s;
};

int main()
{
    String s{"Hello<->World<->Tour"};
    auto s2 = s.to_lower();
    auto words = s2.split("<->");
    for(auto word : words)
    {
        cout << word << ", ";
    }
    cout << endl;
    return 0;
}