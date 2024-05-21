#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
    private:
    public:
        int numerator;
        int denominator;
        Fraction();
        Fraction(int numerator, int denominator);
        void fixSigns();
        void reduceFraction();
        void sumFractions(Fraction f1, Fraction f2);
        void multFractions(Fraction f1, Fraction f2);
};

#endif