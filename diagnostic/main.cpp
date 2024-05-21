#include <iostream>
#include "fraction.h" // change to cpp for compiling
using namespace std;

int main() {
    cout<<"Write the numerator and denominator for the first function (numbers separated by a blank space): ";
    int a,b;
    cin>>a>>b;
    Fraction f1(a, b);
    cout<<"Write the numerator and denominator for the second function (numbers separated by a blank space): ";
    cin>>a>>b;
    Fraction f2(a, b);
    cout<<"Choose desired operation (number)\n1 sum\n2 multiplication\n";
    cin>>a;
    Fraction f3;
    if (a == 1) {
        f3.sumFractions(f1, f2);
        cout<<"Sum result: "<<f3.numerator<<" / "<<f3.denominator;
    } else if (a == 2) {
        f3.multFractions(f1, f2);
        cout<<"Multiplication result: "<<f3.numerator<<" / "<<f3.denominator;
    } else {
        cout<<"No available operation";
    }
    return 0;
}