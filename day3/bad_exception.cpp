#include <iostream>

using namespace std;

int real_main()
{
    return 0;
}

int main()
{
    auto return_value = 0;
    try
    {
        return_value = real_main();
    }
    catch(const exception& e)
    {}
    
    return return_value;
}