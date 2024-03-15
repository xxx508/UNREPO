#include <stdio.h>
#include <cmath>
using namespace std;
class Function {
public:
	virtual double calculate(double x) = 0;
	virtual void printF() = 0;
	virtual void calculateF(double x) = 0;
};

class Powered
{
protected:
	double x;
	int power;
public:
	Powered(double xX = 1, int pow = 1) : x(xX), power(pow) {}
	double calculate() const
	{
		double ret = 1;
		for (int i = 0; i < power; i++) ret *= x;
		return ret;
	}
	void printF ()
	{
		printf("Powered function: %f ^ %d\n", x, power);
	}
	~Powered(){}
	Powered operator=(Powered a)
	{
		x = a.x;
		power = a.power;
		return *this;
	}
	void calculateF()
	{
		printf("Function: "); printF();
		printf("F(%f) = %f\n", x, calculate());
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
		return p.calculate() * arg + adds;
	}
	void printF() override {
		printf("Algebraic function: ");
		if (!(abs(arg - 1) < 0.001))printf("%f *", arg);
		printf("x");
		if (power != 1)printf(" ^ %d", power);
		if (!(adds > -0.001 && adds < 0.001))
		{
			if (adds > 0)printf(" +");
			printf("%f", adds);
		}
		printf("\n");
	}
	~Algebraic(){}
	Algebraic operator=(Algebraic a)
	{
		arg = a.arg;
		adds = a.adds;
		power = a.power;
		return *this;
	}
	void calculateF(double x)
	{
		printf("Function: "); printF();
		printf("F(%f) = %f\n", x, calculate(x));
	}
};

class Trigonometry : public Function {
protected:
	double prearg = 1, inarg = 1;
	int xpow = 1, fpow = 1;
public:
	enum type
	{
		sinus = 1, cosinus, tangens, cotangens
	} Ft;
	Trigonometry(double FunctionArgument = 1, double XArgument = 1, int XPower = 1, int FunctionPower = 1, type FunctionType = (type)1) :
		prearg(FunctionArgument), inarg(XArgument), xpow(XPower), Ft(FunctionType), fpow(FunctionPower) {};
	double calculate(double x) override {
		Powered XUncut(x, xpow);
		double FUncut = 1;
		switch (Ft)
		{
		case 1: FUncut = sin(XUncut.calculate()); break;
		case 2: FUncut = cos(XUncut.calculate()); break;
		case 3: FUncut = tan(XUncut.calculate()); break;
		case 4: FUncut = 1 / tan(XUncut.calculate()); break;
		default: printf("\nError with Function-type\n"); break;
		}
		Powered Func(FUncut, fpow);
		return Func.calculate();
	}
	void printF() override {
		if (!(abs(prearg - 1) < 0.001)) printf("%f * ", prearg);
		switch (Ft)
		{
		case 1: printf("sin("); break;
		case 2: printf("cos("); break;
		case 3: printf("tan("); break;
		case 4: printf("ctg("); break;
		default: printf("\nError with Function-type\n"); break;
		}
		if (!(abs(inarg - 1) < 0.001)) printf("%f * x", inarg);
		if (xpow != 1)printf(" ^ %d", xpow);
		printf(")");
		if (fpow != 1)printf(" ^ %d", fpow);
		printf("\n");
	}
	~Trigonometry(){}
	Trigonometry operator=(Trigonometry a)
	{
		fpow = a.fpow;
		xpow = a.xpow;
		Ft = a.Ft;
		prearg = a.prearg;
		inarg = a.inarg;
		return *this;
	}
	void calculateF(double x)
	{
		printf("Function: "); printF();
		printf("F(%f) = %f\n", x, calculate(x));
	}
};

class Logar2: public Function
{
protected:
	double arg;
public:
	Logar2 (int a = 2) : arg(a) {}
	double calculate(double x = 2.0)
	{
		arg = (abs((arg - 2)) < 0.001 ? x : arg);
		return log2(arg);
	}
	~Logar2(){}
	void printF() override
	{
		printf("Log2 function: log2(%f) = %f\n", arg, this->calculate());
	}
	Logar2 operator=(Logar2 a)
	{
		arg = a.arg;
		return *this;
	}
	void calculateF(double x)
	{
		if (x <= 0)
		{
			printf("Unsupported argument in function call. Argument = 2.\n");
			x = 2;
		}
		arg = x;
		printf("Function: "); printF();
		printf("F(%f) = %f\n", arg, calculate(arg));
	}
};