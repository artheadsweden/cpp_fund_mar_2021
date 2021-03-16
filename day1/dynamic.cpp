#include <iostream>

using namespace std;

int main()
{
    {
        int x = 10;
    }
    {
        int* ip = new int;
        *ip = 20;
        cout << *ip << endl;
        delete ip;
    }
    return 0;
}