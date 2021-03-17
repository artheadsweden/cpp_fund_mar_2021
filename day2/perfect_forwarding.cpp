#include <iostream>
#include <string>

using namespace std;

void process(string& arg)
{
    cout << "lvalue process" << endl;
}

void process(string&& arg)
{
    cout << "rvalue process" << endl;
}

template <typename T>
void log_and_process(T&& param)
{
    // Do some logging
    process(forward<T>(param));
}

int main()
{
    string value = "hi";
    log_and_process(value);
    return 0;
}