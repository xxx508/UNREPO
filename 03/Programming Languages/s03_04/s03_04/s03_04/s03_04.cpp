#include <iostream>
#include "funcs.h"

using namespace std;

int main() {
	Algebraic A1(3, 2, 0), A2(9.5, 10, 6.9);
	Trigonometry T1(4, 6, 7, 2, Trigonometry::type(1)), T2(2, 5, 1, 1, Trigonometry::type(2));
	Logar2 L1(3), L2(12);
	Powered P1(6, 7), P2(1, 100);
	A1.calculateF(12.5); A2.calculateF(4.5);
	T1.calculateF(7.3); T2.calculateF(-3.3);
	L1.calculateF(5); L2.calculateF(4);
	P1.calculateF(); P2.calculateF();
	system("Pause");
	return 0;
}