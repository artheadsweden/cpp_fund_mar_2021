#include <iostream>
#include <string>

using namespace std;

int main()
{
    auto maximum = [](auto a, auto b) {return a > b ? a : b;};
    cout << maximum(10, 15) << endl;
    cout << maximum(24, 15) << endl;
    cout << maximum(24.4, 24.6) << endl;
    cout << maximum("anna"s, "bob"s) << endl;
    cout << maximum(24, 23.4) << endl;
    return 0;
}