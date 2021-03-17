#include <iostream>

using namespace std;

void println()
{
    cout << endl;
}

template <typename Head, typename ... Tail>
void println(Head const& head, Tail const& ... tail)
{
    cout << head;
    if(sizeof ...(tail))
    {
        cout << ", ";
    }
    println(tail...);
}

int main()
{
    int arr[] {2, 5, 7, 9};
    println("Hello", "World", 1, 3.4f, *arr);
    return 0;
}