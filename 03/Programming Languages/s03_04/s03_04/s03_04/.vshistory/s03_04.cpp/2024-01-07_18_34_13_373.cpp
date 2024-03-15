#include <iostream>
#include "funcs.h"

using namespace std;

int main() {
    AlgebraicFunction af(1, 2, 1);
    LinearFunction lf(2, 3);
    QuadraticFunction qf(1, 2, 1);

    cout << "Algebraic Function: " << af.calculate(2) << endl;
    cout << "Linear Function: " << lf.calculate(2) << endl;
    cout << "Quadratic Function: " << qf.calculate(2) << endl;

    af.printthisF();
    lf.printthisF();
    qf.printthisF();
    return 0;
}