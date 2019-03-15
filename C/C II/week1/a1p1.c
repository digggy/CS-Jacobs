/*
JTSK-320112
Problem 1.1
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <stdio.h>

#define SWAP(A,B,TYPE) { TYPE C = A; A=B; B =C;} 

int main(int argc,char** argv){
    int a,b;
    double c,d;

    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%lf",&c);
    scanf("%lf",&d);

    SWAP(a,b,int);
    SWAP(c,d,double);
    
    printf("After swapping:\n");
    printf("%d\n",a);
    printf("%d\n",b);
    printf("%.6lf\n",c);
    printf("%.6lf\n",d);

    return 0;
}