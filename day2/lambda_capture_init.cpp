#include <iostream>

using namespace std;

int main()
{
    auto g = [x=0]() mutable
    {
        //cout << x << endl;
        return x++;
    };
    cout << g() << endl;
    cout << g() << endl;
    cout << g() << endl;
    cout << g() << endl;
    cout << g() << endl;
    return 0;
}