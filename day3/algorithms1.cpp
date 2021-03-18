#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    vector<int> values;
    generate_n(back_inserter(values), 10, [](){return 10;});
    for_each(values.begin()+3, values.end(), [](auto n) {cout << n << " ";});
    cout << endl;

    vector<int> v2 {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
    // {1, 3, 4, 1, 3, 4, 1, 3, 4, 2, 2, 2}
    // for(auto it = v2.begin(); it != v2.end(); it++)
    // {
    //     if(*it == 2)
    //     {
    //         v2.erase(it);
    //     }
    // }
    auto to_erase = remove_if(v2.begin(), v2.end(),[](auto elem) {return elem==2;});
    v2.erase(to_erase, end(v2));
    for_each(v2.begin(), v2.end(), [](auto n) {cout << n << " ";});
    cout << endl;

    return 0;
}