#include <iostream>

using namespace std;

class Temperature
{
public:
    // Constructors
    Temperature();
    explicit Temperature(double t);
    Temperature(const Temperature& other);

    double get_celsius() const;
    double get_fahrenheit() const;
    void set_celsius(double t);
    void set_fahrenheit(double t);

    Temperature& operator=(const Temperature& other);
    Temperature operator+(const Temperature& other) const;
    Temperature operator-(const Temperature& other) const;
    Temperature operator*(const Temperature& other) const;
    Temperature operator/(const Temperature& other) const;
    Temperature operator+(const double& other) const;
    Temperature operator-(const double& other) const;
    Temperature operator*(const double& other) const;
    Temperature operator/(const double& other) const;

    // Friend functions
    friend Temperature operator+(const double& first, const Temperature& other);
    friend Temperature operator-(const double& first, const Temperature& other);
    friend Temperature operator*(const double& first, const Temperature& other);
    friend Temperature operator/(const double& first, const Temperature& other);
    friend ostream& operator<<(ostream& os, const Temperature&other);
private:
    double temp_;
};

Temperature::Temperature() : temp_{0.0}{}

Temperature::Temperature(double t) : temp_{t}{}

Temperature::Temperature(const Temperature& other) : temp_{other.temp_}{}

double Temperature::get_celsius() const
{
    return temp_;
}

double Temperature::get_fahrenheit() const
{
    return temp_ * 9 / 5 + 32;
}

void Temperature::set_celsius(double t)
{
    temp_ = t;
}

void Temperature::set_fahrenheit(double t)
{
    temp_ = (t - 32) * 5 / 9;
}

Temperature& Temperature::operator=(const Temperature& other)
{
    cout << "Assign" << endl;
    temp_ = other.temp_;
    return *this;
}

Temperature Temperature::operator+(const Temperature& other) const
{
    return Temperature(temp_ + other.temp_);
}

Temperature Temperature::operator-(const Temperature& other) const
{
    return Temperature(temp_ - other.temp_);
}

Temperature Temperature::operator*(const Temperature& other) const
{
    return Temperature(temp_ * other.temp_);
}

Temperature Temperature::operator/(const Temperature& other) const
{
    return Temperature(temp_ / other.temp_);
}

Temperature Temperature::operator+(const double& other) const
{
    return Temperature(temp_ + other);
}

Temperature Temperature::operator-(const double& other) const
{
    return Temperature(temp_ - other);
}

Temperature Temperature::operator*(const double& other) const
{
    return Temperature(temp_ * other);
}

Temperature Temperature::operator/(const double& other) const
{
    return Temperature(temp_ / other);
}

Temperature operator+(const double& first, const Temperature& other)
{
    return Temperature(first + other.temp_);
}

Temperature operator-(const double& first, const Temperature& other)
{
    return Temperature(first - other.temp_);
}

Temperature operator*(const double& first, const Temperature& other)
{
    return Temperature(first * other.temp_);
}

Temperature operator/(const double& first, const Temperature& other)
{
    return Temperature(first / other.temp_);
}

ostream& operator<<(ostream& os, const Temperature&other)
{
    os << other.temp_;
    return os;
}


int main()
{
    Temperature t1(10);
    Temperature t2;
    t2.set_fahrenheit(100);
    auto t3 = 3.45 + t1;
    auto t4 = t1 + 3.56;
    cout << t3 << endl;
    cout << t4 << endl;
    cout << t2 << endl;
    Temperature t5;
    t5 = t4;
    cout << t5 << endl;
    return 0;
}