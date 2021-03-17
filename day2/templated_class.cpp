#include <iostream>

using namespace std;

template <typename T>
class Calc
{
public:
    T add(T a, T b)
    {
        return a + b;
    }

    T multiply(T a, T b)
    {
        return a * b;
    }
};

int main()
{
    Calc<int> int_calc;
    cout << int_calc.add(3, 4) << endl;
    cout << int_calc.multiply(3, 4) << endl;

    Calc<double> double_calc;
    cout << double_calc.add(3.34, 4.56) << endl;
    cout << double_calc.multiply(3.56, 4.65) << endl;

    return 0;
}