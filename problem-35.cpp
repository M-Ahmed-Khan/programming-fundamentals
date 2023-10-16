#include <iostream>
#define pi 3.14
/* Creates a "Shape" base class with a method "area()" and
two derived classes "Circle" and "Square" and implements
the "area()" method in each derived class to calculate the
area of the circle and square, respectively */

using namespace std;

class Shape
{
protected:
    virtual float area() = 0;
};

class Square : protected Shape
{
public:
    float length;

    float area()
    {
        return length * length;
    }
};

class Circle : protected Shape
{
public:
    float radius;

    float area()
    {
        return pi * (radius * radius);
    }
};

int main()
{
    Square square;
    Circle circle;

    cout << "Enter length of a side of square: ";
    cin >> square.length;

    cout << "The area of the square is " << square.area() << endl
         << endl;

    cout << "Enter length of a side of circle: ";
    cin >> circle.radius;

    cout << "The area of the circle is " << circle.area() << endl
         << endl;

    return 0;
}