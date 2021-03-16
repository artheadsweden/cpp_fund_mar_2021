#include <iostream>

using namespace std;

class Temperature
{
    //F = C * 9 / 5 + 32
};

int main()
{
    Temperature t1(3.45);
    Temperature t2(14.9);
    Temperature t3 = t1 + t2;
    Temperature t4 = t1 + 22.3;
    Temperature t5 = 13.7 + t2;
    cout << t1 << endl;
    return 0;
}