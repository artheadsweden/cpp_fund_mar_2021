#include <iostream>

using namespace std;

class Temperature
{
public:
    // Constructors
    Temperature();
    explicit Temperature(double t);
    Temperature(const Temperature& other);
    ~Temperature();

    Temperature& operator=(const Temperature& other);

private:
    double* temp_;
};

Temperature::Temperature() : temp_{new double(0.0)}{}

Temperature::Temperature(double t) : temp_{new double (t)}{}

Temperature::Temperature(const Temperature& other) : temp_{new double(*other.temp_)}{}

Temperature::~Temperature()
{
    delete temp_;
}

Temperature& Temperature::operator=(const Temperature& other)
{
    cout << "Assign" << endl;
    temp_ = new double(*other.temp_);
    return *this;
}


int main()
{
    
    return 0;
}