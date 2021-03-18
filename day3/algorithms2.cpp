#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int fib_func(int n)
{
    if(n <= 1)
    {
        return n;
    }
    return fib_func(n-1) + fib_func(n-2);
}

int main()
{
    auto print = [](auto comment, auto const& seq)
    {
        cout << comment << ": ";
        for(const auto& e : seq)
        {
            cout << e << " ";
        }
        cout << endl;
    };
    vector<int> fibs;

    auto fib = [](int n, auto&& fib) 
    {
        if(n <= 1)
        {
            return n; 
        }
        return fib(n-1, fib) + fib(n-2, fib);
    };

    int i = 1;
    generate_n(back_inserter(fibs), 15, [&i, &fib]{
                                                    return fib(i++, fib);
                                                  });
    
    print("Fibs", fibs);

    int total = accumulate(fibs.begin(), fibs.begin()+3, 0);
    cout << "The total sum of the first 15 fibs = " << total << endl;
    return 0;
}