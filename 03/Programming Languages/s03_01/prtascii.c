#include <stdio.h>
int main(){
    int ins = 'a';
    printf("ins is now %c and %i\n", ins, ins);
    while(ins!='q'){
        printf("%c is %i\n",ins,ins);
	ins = getchar();
	getchar();
}
    return 0;
}
