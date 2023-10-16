#include <iostream>
#include <string>
/* Creates a "Rectangle" class with attributes "width" and "height".
and implements methods to calculate the "area" and "perimeter" of
the rectangle */

using namespace std;

class Rectangle
{
public:
    float width;
    float height;

    Rectangle(float width, float height)
    {
        this->width = width;
        this->height = height;
    }

    float getArea()
    {
        return width * height;
    }

    float getPerimeter()
    {
        return 2 * (width + height);
    }
};

int main()
{
    float userWidth, userHeight;

    cout << "Enter the width of Rectangle: ";
    cin >> userWidth;

    cout << "Enter the height of Rectangle: ";
    cin >> userHeight;

    Rectangle rectangle(userWidth, userHeight);

    cout << "\nArea: " << rectangle.getArea();
    cout << "\nPerimeter: " << rectangle.getPerimeter();

    return 0;
}