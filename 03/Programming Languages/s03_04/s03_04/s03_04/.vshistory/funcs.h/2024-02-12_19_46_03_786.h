#include <stdio.h>
#include <cmath>

class Function {
public:
    virtual double calculate(double x) = 0;
    virtual void printF() = 0;
};

class Powered
{
protected:
    double x;
    int power;
public:
    Powered(double xX = 1, int pow = 1) : x(xX), power(pow) {};
    double calc() const
    {
        double ret = 1;
        for (int i = 0; i < power; i++) ret *= x;
        return ret;
    }
};

class Algebraic : public Function {
protected:
    double arg, adds;
    int power;
public:
    Algebraic(double Farg = 1, int pow = 1, double add = 0) : arg(Farg), adds(add), power(pow) {};
    double calculate(double x) override {
        Powered p(x, power);
        return p.calc() * arg + adds;
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
    int xpow = 1, fpow = 1;
    enum type
    {
        sin = 1, cos, tan, cot
    } Ft;
public:
    Trigonometry(double Farg = 1, double Xarg = 1, int Xpow = 1, int Fpow = 1, type Ftype = sin) : prearg(Farg), inarg(Xarg), pow(Xpow), Ft(Ftype) {};
    double calculate(double x) override {

    }
    void printF() override {
        Powered ()
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

    void printF() override {
        printf("Quadratic Function: %f * x^2 + %f * x + %f\n", a, b, c);
    }
};