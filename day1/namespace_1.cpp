#include <iostream>

using namespace std; 

namespace mine
{
    int abs(int x)
    {
        return x + 1;
    }
}


int main() 
{
    cout << abs(-5) << endl;
    std::cout << mine::abs(-5) << std::endl;
    return 0;
}