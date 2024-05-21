#include <iostream>
#include "Shape.cpp"
#include "Circle.cpp"
#include "Rectangle.cpp"
using namespace std;

int main()
{
    Shape s1(1, 2);
    cout << s1.draw() << "@(" << s1.getX() << ", " << s1.getY() << ")" << endl;
    Circle c1(2, 3, 5);
    cout << c1.draw() << "@(" << c1.getX() << ", " << c1.getY() << ")" << endl;
    Rectangle r1(5, 6, 10, 20);
    cout << r1.draw() << "@(" << r1.getX() << ", " << r1.getY() << ")" << endl;
return 0;
}