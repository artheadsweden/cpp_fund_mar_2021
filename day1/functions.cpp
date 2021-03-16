#include <iostream>

using namespace std;

int add(int &a, int &b)
{
    cout << "lvalue" << endl;
    return a + b;
}

int add(int &&a, int &&b)
{
    cout << "rvalue" << endl;
    return a + b;
}

int main()
{
    int x = 34;
    int y = 16;
    int result = add(x, y);
    int result2 = add(12, 45);
    cout << result << endl;
    cout << x << endl;
    return 0;
}