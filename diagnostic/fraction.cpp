#include <math.h>
#include "fraction.h"

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
    reduceFraction();
    fixSigns();
}

void Fraction::fixSigns() {
    if (this->denominator < 0) {
        this->numerator *= -1;
        this->denominator *= -1;
    }
}

void Fraction::reduceFraction() {
    int gcd = 1;
    for (int i = 1; i <= abs(numerator) && i <= abs(denominator); i++) {
        if (numerator % i == 0 && denominator % i == 0) {
            gcd = i;
        }
    }
    this->numerator /= gcd;
    this->denominator /= gcd;
}

void Fraction::sumFractions(Fraction f1, Fraction f2) {
    this->numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    this->denominator = f1.denominator * f2.denominator;
    reduceFraction();
    fixSigns();
}

void Fraction::multFractions(Fraction f1, Fraction f2) {
    this->numerator = f1.numerator * f2.numerator;
    this->denominator = f1.denominator * f2.denominator;
    reduceFraction();
    fixSigns();
}