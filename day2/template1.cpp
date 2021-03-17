#include <iostream>
#include <string>

using namespace std;

template <typename T1, typename T2>
auto maximum(T1 a, T2 b) 
{
    return a > b ? a : b;
}


int main()
{
    cout << maximum(10, 15) << endl;
    cout << maximum(24, 15) << endl;
    cout << maximum(24.4, 24.6) << endl;
    cout << maximum("anna"s, "bob"s) << endl;
    cout << maximum(24.4, 23) << endl;
    return 0;
}