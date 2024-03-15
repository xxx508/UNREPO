#include <stdio.h>
#define forn(n) for(int i=0;i<n;i++)
class Function {
public:
    virtual double calculate(double x) = 0;
    virtual void printthisF() = 0;
};

class Algebraic : public Function {
protected:
    double arg, adds;
    int power;
public:
    Algebraic(double argument = 1, int pow = 1, double add = 0) : arg(argument), adds(add), power(pow) {}
    double calculate(double x) override {
        double res = 1;
        for (int i = 0; i < power; i++)res *= x;
        return arg * res + adds;
    }
    void printthisF() override {
        printf("Algebraic Function: %f * x^%d + %f\n", arg, power, adds);
    }
};
class Trigonometry : public Function {
protected:
    double preargs[4], inargs[4];
    int pow[4] = { 1, 1, 1, 1 };
public:
    Trigonometry(double argsfun[4], double argsx[4], int powerx[4])
    {
        forn(4) { preargs[i] = argsfun[i]; inargs[i] = argsx[4]; pow[i] = powerx[i]; }
    }
};
class QuadraticFunction : public Function {
protected:
    double a, b, c;

public:
    QuadraticFunction(double a, double b, double c) : a(a), b(b), c(c) {}

    double calculate(double x) override {
        return a * x * x + b * x + c;
    }

    void printthisF() override {
        printf("Quadratic Function: %f * x^2 + %f * x + %f\n", a, b, c);
    }
};