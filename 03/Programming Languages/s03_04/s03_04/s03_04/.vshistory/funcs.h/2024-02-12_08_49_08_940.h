#include <stdio.h>
class Function {
public:
    virtual double calculate(double x) = 0;
    virtual void printthisF() = 0;
};

class Algebraic : public Function {
protected:
    double arg, adds;
    int power = 1;
public:
    Algebraic(double argument, int pow, double add) : arg(argument), adds(add), power(pow) {}
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
    double argsin[2], argcos[2], argtan[2], argctg[2];

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