#include <iostream>

using namespace std;

auto func()
{
    return 10;
}

int main()
{
    int value = 34;
    
    auto f = [value](int a, int b){
        cout << "Hej" << endl;
        int x = value;
 
        return x + a + b;
    };
    auto result = f(12, 13);
    cout << result << endl;
    return 0;
}