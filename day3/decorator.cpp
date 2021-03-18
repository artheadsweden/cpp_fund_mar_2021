#include <iostream>
#include <functional>
#include <string>

using namespace std;

struct Logger
{
    function<void()> func;
    string name;

    Logger(const function<void()>& func, const string& name) : func{func}, name{name} {}

    void operator()() const
    {
        cout << "Entering " << name << endl;
        func();
        cout << "Exiting " << name << endl;
    }
};


void hello()
{
    cout << "Hello there" << endl;
}

int main()
{
    Logger logger{hello, "hello_func"};
    logger();
    return 0;
}