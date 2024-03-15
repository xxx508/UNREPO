#include <stdio.h>
class Function {
public:
    virtual double calculate(double x) = 0;
    virtual void printthisF() = 0;
};

class Algebraic : public Function {
protected:
    double arg;
public:
    Algebraic(double argument) : arg(argument) {}
    double calculate(double x) override {
        return arg * x;
    }

    void printthisF() override {
        printf("Algebraic Function: %f * x^2 + %f * x + %f\n", a, b, c);
    }
};

class LinearFunction : public Function {
protected:
    double k, b;

public:
    LinearFunction(double k, double b) : k(k), b(b) {}

    double calculate(double x) override {
        return k * x + b;
    }

    void printthisF() override {
        printf("Linear Function: %f * x + %f\n", k, b);
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