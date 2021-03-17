#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MyClass
{
public:
    MyClass() : value_(nullptr)
    {
        cout << "Default Constructor" << endl;
    }

    MyClass(int v) : value_(new int(v)) 
    {
        cout << "Constructor with value " << v << endl;
    }

    MyClass(const MyClass& other) : value_(new int(*other.value_))
    {
        cout << "Copy Constructor" << endl;
    }

    MyClass(MyClass&& other) : value_(nullptr)
    {
        swap(value_, other.value_);
        cout << "Move Constructor" << endl;
    }

    ~MyClass()
    {
        delete value_;
        cout << "Destructor" << endl;
    }

    MyClass& operator=(const MyClass& other)
    {
        value_ = new int(*other.value_);
        cout << "Copy Assignment Operator" << endl;
        return *this;
    }

    MyClass& operator=(MyClass&& other)
    {
        value_ = nullptr;
        swap(value_, other.value_);
        cout << "Move Assignment Operator" << endl;
        return *this;
    }

    void print()
    {
        if(value_ != nullptr)
        {
            cout << *value_ << endl;
        }
        else
        {
            cout << "null" << endl;
        }
    }
private:
    int* value_;
};


int main()
{
    vector<MyClass> my_vect;
    for(int i = 0; i < 100; i++)
    {
        my_vect.push_back(MyClass(i));
    }
    return 0;
}