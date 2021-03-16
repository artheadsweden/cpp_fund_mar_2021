#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 2, 7, 2, 2, 8, 9};
    vector<int>::iterator it = numbers.begin();
    while(it != numbers.end())
    {
        if(*it == 2)
        {
            numbers.erase(it);
        }
        else{
            it++;
        }
    }
    for(auto number : numbers)
    {
        cout << number << ", ";
    }
    cout << endl;
    return 0;
}