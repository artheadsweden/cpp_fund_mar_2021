#include <iostream>

using namespace std;

class String
{
public:
    //Konstruktor som tar ett argument, en sträng
    //En to_lower() som returnerar ett nytt objekt från String
    //En split(const string& deli=" ") som tar en avgränsare och returnerar en vector<string>
private:  
    string s;
};

int main()
{
    String s{"Hello World Tour"};
    auto s2 = s.to_lower();
    auto words = s2.split();
    for(auto word : words)
    {
        cout << word << ", ";
    }
    cout << endl:
    return 0;
}