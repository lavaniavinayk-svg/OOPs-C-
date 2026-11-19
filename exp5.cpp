#include <iostream>
using namespace std;

class Shape
{
public:
    virtual double area() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r)
    {
        radius = r;
    }

    double area() override
    {
        return 3.14159 * radius * radius;
    }
};

// Derived class 2
class Rectangle : public Shape
{
private:
    double length, breadth;

public:
    Rectangle(double l, double b)
    {
        length = l;
        breadth = b;
    }

    double area() override
    {
        return length * breadth;
    }
};

// Derived class 3
class Triangle : public Shape
{
private:
    double base, height;

public:
    Triangle(double b, double h)
    {
        base = b;
        height = h;
    }

    double area() override
    {
        return 0.5 * base * height;
    }
};

int main()
{
    Circle c(5);
    Rectangle r(4, 6);
    Triangle t(8, 3);

    Shape* shape[] = {&c, &r, &t};

    for (int i = 0; i < 3; i++)
    {
        cout << "Area: " << shape[i]->area() << endl;
    }

    return 0;
}