#include <iostream>

using namespace std;


int main()
{
    int x = 10;
    int* ip = &x;
    int** ipp = &ip;
    cout << x << endl;
    cout << *ip << endl;
    cout << **ipp << endl;
    return 0;
}