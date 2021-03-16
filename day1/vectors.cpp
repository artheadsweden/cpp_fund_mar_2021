#include <iostream>
#include <vector>

using namespace std;
// xyz
// 1, 2, 3, 4, 17                  
int main()
{
    vector<int> numbers = {1, 2, 3, 4, 5};
    for(auto number : numbers)
    {
        cout << number << endl;
    }

    numbers.push_back(17);
    for(auto number : numbers)
    {
        cout << number << endl;
    }
    numbers.pop_back();
    
    for(auto number : numbers)
    {
        cout << number << endl;
    }

    numbers[3] = 99;
    for(auto number : numbers)
    {
        cout << number << endl;
    }
    //cout << numbers[7] << endl;
    numbers.erase(numbers.begin()+2);
    numbers.insert(numbers.begin()+3, 77);
    for(auto number : numbers)
    {
        cout << number << endl;
    }
    return 0;
}