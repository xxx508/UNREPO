#include <iostream>
#include <stdio.h>
#include "vect.h"
using namespace std;

int main(){
    int i=20;
    while(i--)printf("*");
    printf("\n");
    vector a, b, c;
    a.assign(1, 2, 3);
    b.assign(10,10,10);
    printf("Vect a:\t");
    a.show();
    printf("Vect b:\t");
    b.show();
    c=a+b;
    printf("Vect a+b=c:\t");
    c.show();
    c=a;
    printf("Vect c=a:\t");
    c.show();
    getchar();
    return 0;
}