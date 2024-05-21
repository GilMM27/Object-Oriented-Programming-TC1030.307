#ifndef SHAPE
#define SHAPE
#include <iostream>

using namespace std;

class Shape
{
    private:
        int x;
        int y;
    public:
        Shape();
        Shape(int, int);
        virtual string draw();
        int getX();
        int getY();
};
#endif