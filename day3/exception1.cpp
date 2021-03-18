#include <iostream>
#include <vector>

using namespace std;

int func(int index)
{
    // Something went wrong!
    vector<int> v{1, 2, 3};
    auto y = v.at(index);
    return 0;
}

int main()
{
    func(10);
    vector<int> v{1, 2, 3};
    auto y = v.at(10);
    try
    {
        auto x = v.at(10);
        cout << x << endl;
    }
    catch(const out_of_range& e)
    {
        cerr << "We are out of range!" << endl << e.what() << '\n';
    }
    catch(const exception& e)
    {
        cerr << "We got an exception!" << endl << e.what() << '\n';
    }
    return 0;
}