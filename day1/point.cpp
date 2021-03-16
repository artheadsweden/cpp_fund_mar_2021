#include <iostream>

using namespace std;

class Point
{
public:
    Point() : x_{0}, y_{0} {cout << "Default Constructor" << endl;}
    Point(int x, int y) : x_{x}, y_(y) {cout << "Constructor With Argument" << endl;}
    Point(const Point& other) : x_{other.x_}, y_{other.y_} {cout << "Copy Constructor" << endl;}
    
    Point& operator=(const Point& other)
    {
        x_ = other.x_;
        y_ = other.y_;
        cout << "Assignment Operator" << endl;
        return *this;
    }

    Point operator+(const Point& other)
    {
        cout << "Addition" << endl;
        return Point(x_ + other.x_, y_ + other.y_);
    }

    void print()
    {
        cout << "x_: " << x_ << " y_: " << y_ << endl;
    }
private:
    int x_;
    int y_;
};

class Point2
{
public:
    Point2() : x_{0} {cout << "Default Constructor" << endl;}
    Point2(int x) : x_{x} {cout << "Constructor With Argument" << endl;}
    Point2(const Point2& other) : x_{other.x_} {cout << "Copy Constructor" << endl;}
    
    Point2& operator=(const Point2& other)
    {
        x_ = other.x_;

        cout << "Assignment Operator" << endl;
        return *this;
    }

    Point2 operator+(const Point2& other)
    {
        cout << "Addition" << endl;
        return Point2(x_ + other.x_);
    }

    friend Point2 operator+(const int& value, const Point2& other);
    friend ostream& operator<<(ostream& os, const Point2& other);

    void print()
    {
        cout << "x_: " << x_ <<  endl;
    }
private:
    int x_;

};

Point2 operator+(const int& value, const Point2& other)
{
    cout << "Addition" << endl;
    return Point2(value + other.x_);
}


ostream& operator<<(ostream& os, const Point2& other)
{
    os << "x_: " << other.x_;
    return os;
}

int main()
{
    Point p1(15, 17);
    Point p2 = p1;
    Point p3;
    Point p4;
    p4 = p3 = p1;

    Point p5 = p1 + p2;
    p5.print();
    //Point p7 = p1 + 2;

    cout << "------" << endl;
    Point2 one_point(34);
    Point2 p6 = one_point + 3;
    Point2 p7 = 3 + one_point;
    cout << "p7 has the value " << p7 << endl;
    return 0;
}