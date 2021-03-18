#include <iostream>

using namespace std;

class Banana : public exception
{
public:
    Banana(int number, const char* message) : error_number{number}, error_message{message} {} 
    const char* what() const throw(){
        return error_message;
    }
private:
    int error_number;
    const char* error_message;
};

void faulty_func(int age)
{
    if (age >= 18)
    {
        cout << "Access granted" << endl;
    }
    else
    {
        throw Banana(age, "You are very young!");
    }
}

int main()
{
    try
    {
        faulty_func(17);
    }
    catch(const Banana& e)
    {
        cerr << "Age error: " << endl << e.what() << '\n';
    }
    
    return 0;
}