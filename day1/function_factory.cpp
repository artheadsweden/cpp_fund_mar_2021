#include <iostream>

using namespace std;



int main()
{
    
    auto function_factory = [](int x)
    {
        return [=](int y) {
            return x * y;
        };
    };

    auto f1 = function_factory(2);
    auto f2 = function_factory(3);
    auto f3 = function_factory(4);
    cout << f1(10) << endl;
    cout << f2(10) << endl;
    cout << f3(10) << endl;
    return 0;
}