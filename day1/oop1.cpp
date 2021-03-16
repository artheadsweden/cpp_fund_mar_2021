#include <iostream>

using namespace std;

class A
{
public:
    A() : x_(0)
    {
        cout << "Default Constructor in A" << endl;
    }

    A(int n) : x_{n}
    {
        cout << "Constructor for A with argument " << n << endl;
    }

    void set_x(int x)
    {
        x_ = x;
    }

    void print()
    {
        cout << x_ << endl;
    }
private:
    int x_;
};

class B
{
public:
    B(int n) : a_(n)
    {
        cout << "Constructor for B with argument " << n << endl;
    }
private:
    A a_;
};

int main()
{
    A a;
    a.print();
    B b(10);
    return 0;
}