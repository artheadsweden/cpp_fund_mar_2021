#include <iostream>
#include <vector>

using namespace std;

class Shape
{
public:
    Shape(double w, double h): width_{w}, height_{h}{}
    virtual double area() = 0;
protected:
    double width_;
    double height_;
};

class Rectangle : public Shape
{
public:
    Rectangle(double w, double h): Shape(w, h) {}
    double area() override
    {
        return width_ * height_;
    }
};

class Triangle: public Shape
{
public:
    Triangle(double w, double h): Shape(w, h) {}
    double area() override
    {
        return width_ * height_ / 2;
    }
};

void print_area(Shape* shape)
{
    cout << shape->area() << endl;
}

int main()
{
    //Shape s(10, 10);

    Shape* shape_ptr;
    Rectangle r1(20, 10);
    Triangle t1(20, 10);
    vector<Shape*> things = {&r1, &t1};

    for(Shape* s : things)
    {
        print_area(s);
    }

    return 0;
}

