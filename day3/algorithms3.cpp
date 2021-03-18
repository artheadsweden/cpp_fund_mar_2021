#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int main()
{
    auto print = [](auto comment, auto const& seq)
    {
        cout << comment;
        for(const auto& e : seq)
        {
            cout << e << " ";
        }
        cout << endl;
    };

    vector<char> v1 {'1', '2', '3', '4', '5', '6'};
    vector<char> v2 {'a', 'b', 'c', 'd', 'e', 'f'};
    print("Before swap_ranges: \nv1: ", v1);
    print("v2: ", v2);

    swap_ranges(v1.begin(), v1.begin()+3, v2.begin()+1);
    print("After swap_ranges: \nv1: ", v1);
    print("v2: ", v2);

    return 0;
}