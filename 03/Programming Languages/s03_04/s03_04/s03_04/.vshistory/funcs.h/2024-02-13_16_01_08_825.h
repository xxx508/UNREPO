#include <stdio.h>
#include <cmath>
using namespace std;
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
		if (!(abs(arg - 1) < 0.001))printf("%f *", arg);
		printf("x");
		if (power != 1)printf(" ^ %d", power);
		if (!(adds > -0.001 && adds < 0.001))
		{
			if (adds > 0)printf(" +");
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
		sinus = 1, cosinus, tangens, cotangens
	} Ft;
public:
	Trigonometry(double FunctionArgument = 1, double XArgument = 1, int XPower = 1, int FunctionPower = 1, type FunctionType = sinus) :
		prearg(FunctionArgument), inarg(XArgument), xpow(XPower), Ft(FunctionType), fpow(FunctionPower) {};
	double calculate(double x) override {
		Powered XUncut(x, xpow);
		double FUncut = 1;
		switch (Ft)
		{
		case 1: FUncut = sin(XUncut.calc()); break;
		case 2: FUncut = cos(XUncut.calc()); break;
		case 3: FUncut = tan(XUncut.calc()); break;
		case 4: FUncut = 1 / tan(XUncut.calc()); break;
		default: printf("\nError with Function-type\n"); break;
		}
		Powered Func(FUncut, fpow);
		return Func.calc();
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
		if (fpow != 1)printf(" ^ %d\n", fpow);
	}
};

class Str
{
private:
	char* StrChar = new char[1];
	int StrLen;
public:
	Str(char* c = nullptr)
	{
		while (c != nullptr)
		{
			char* cp = StrChar;
			StrChar = new char[++StrLen];
			for (int i = 0; i < StrLen - 1; i++)
			{
				StrChar[i] = cp[i];
			}
			StrChar[StrLen - 1] = *c;
			c++;
		}
	}
	char* ret()
	{

	}
};

class expressiontool
{
	str OrigString
};