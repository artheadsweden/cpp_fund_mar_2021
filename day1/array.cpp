#include <iostream>

using namespace std;

int main()
{
    int numbers[3];
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;

    int x = 10;
    int size;
 
    int* arr_ptr = numbers;
    cout << "Second value: " << numbers[1] << endl;
    cout << "Array Pointer: " << *arr_ptr << endl;
    arr_ptr++;
    cout << "Array Pointer: " << *arr_ptr << endl;
    arr_ptr++;
    cout << "Array Pointer: " << *arr_ptr << endl;
    arr_ptr++;
    cout << "Array Pointer: " << *arr_ptr << endl;
    //*arr_ptr = 99;

    for(int i = 0; i < 3; i++)
    {
       cout << numbers[i] << endl; 
    }

    for(auto number : numbers)
    {
        cout << number << endl;
    }

    int numbers2[] = {1, 2, 3, 4, 5, 6};
    for(auto number : numbers2)
    {
        cout << number << endl;
    }

    return 0;
}