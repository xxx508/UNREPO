#include <iostream>
#include <stdio.h>
#include "vect2.h"
using namespace std;

int main(){
    int i=20;
    while(i--)printf("*");
    printf("\n");
    vector a(1,2,3), b(10,10,10), c;
    printf("vect A:\t");
    a.show();
    printf("vect B:\t");
    b.show();
    printf("vect C:\t");
    c.show();
    printf("vect a+b:\t");
    c=a+b;
    c.show();
    printf("vect a+b+c:\t");
    c=c+a+b;
    c.show();
    getchar();
    return 0;
}