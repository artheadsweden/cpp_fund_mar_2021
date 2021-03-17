#include <iostream>

using namespace std;

class One
{
public:
    One(int& v) : value(v) {}
    void operator()() const
    {
        value = 20;
    }
private:
    int& value;
};

class Two
{
public:
    Two(int& v) : value(v) {}
    void operator()()
    {
        value = 20;
    }
private:
    int value;
};

class Three
{
public:
    Three(int& v) : value(v) {}
    void operator()() const
    {
        value = 20;
    }
private:
    int value;
};

int main()
{
    int x = 10;
    One one(x);
    one();
    Two two(x);
    two();
    Three three(x);
    three();
    return 0;
}