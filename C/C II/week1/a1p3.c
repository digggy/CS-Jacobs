/*
JTSK-320112
Problem 1.3
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <stdio.h>

#define MAX(A,B,C) ((A>B)?((A>C)?A:C):(B>C)?B:C)
#define MIN(A,B,C) ((A<B)?((A<C)?A:C):(B<C)?B:C)
#define MID_RANGE(A, B, C) ((double)(MAX(A,B,C)+MIN(A,B,C))/2)

int main(int argc,char** argv){
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    printf("The mid-range is: %.6lf\n",MID_RANGE(a,b,c));

    return 0;
}
