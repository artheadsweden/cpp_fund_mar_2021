#include <iostream>

using namespace std;

int main()
{
    int x = 10;
    auto f = [x]() mutable
    {
        x++;
    };
    x++;
    cout << x << endl;
    f();
    cout << x << endl;
    x++;
    f();
    cout << x << endl;
    return 0;
}