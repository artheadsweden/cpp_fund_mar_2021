#include <iostream>
#include <memory>

using namespace std;

class MyClass
{
public:
    ~MyClass()
    {
        cout << "Delete" << endl;
    }

    void print()
    {
        cout << "I am alive!" << endl;
    }
};

int main()
{
    // RAII
    weak_ptr<MyClass> wptr;
    {
        //MyClass* ip = new MyClass();
        //delete ip;
        //unique_ptr<MyClass> mcp(new MyClass());
        unique_ptr<int> intptr = make_unique<int>();
        *intptr = 10;
        cout << *intptr << endl;
        
        unique_ptr<MyClass> mcp1 = make_unique<MyClass>();
        auto mcp2 = make_unique<MyClass>();
        //auto mcp3 = mcp2;


        shared_ptr<MyClass> smcp1 = make_shared<MyClass>();
        auto smcp2 = smcp1;
        wptr = smcp1;

        cout << "Done " << wptr.expired() <<  endl;
        MyClass mc;
        //shared_ptr<MyClass> m = &mc;

    }

    cout << "Done " << wptr.expired() <<  endl;
    return 0;
}