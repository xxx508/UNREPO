#include <stdio.h>
#include <cmath>
class Function {
public:
    virtual double calculate(double x) = 0;
    virtual void printF() = 0;
};

class Algebraic : public Function {
protected:
    double arg, adds;
    int power;
public:
    Algebraic(double Farg = 1, int pow = 1, double add = 0) : arg(Farg), adds(add), power(pow) {}
    double calculate(double x) override {
        double res = 1;
        for (int i = 0; i < power; i++)res *= x;
        return arg * res + adds;
    }
    void printF() override {
        printf("Algebraic function: ");
        if (!(arg - 1 < 0.001))printf("%f *", arg);
        printf("x ");
        if (power != 1)printf("^ %d ", power);
        if (!(adds > -0.001 && adds < 0.001))
        {
            if (adds > 0)printf("+");
            printf("%f\n", adds);
        }
    }
};
class Trigonometry : public Function {
protected:
    double prearg = 1, inarg = 1;
    int pow = 1;
    enum type
    {
        sin = 1, cos, tan, cot
    } Ft;
public:
    Trigonometry(double Farg = 1, double Xarg = 1, int Xpow = 1, type Ftype = sin) : prearg(Farg), inarg(Xarg), pow(Xpow), Ft(Ftype) {};
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