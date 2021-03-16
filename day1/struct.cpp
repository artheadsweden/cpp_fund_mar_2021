#include <iostream>
#include <string>
using namespace std;


struct Person1
{
    string name;
    char sex;
    short age;
    string email;
};

class Person2
{
public:
    string get_name() 
    {
        return name;
    }
    void set_name(string n)
    {
        name = n;
    }
private:
    string name;

};


int main()
{
    Person2 a;
    Person1 b;
    a.name = "Ture";
    a.set_name("Alice");


    b.name = "Bob";
    b.sex = 'M';
    b.age = 34;
    b.email = "bob@email.com";
    cout << "Hello " << a.get_name() << endl;
    return 0;
}