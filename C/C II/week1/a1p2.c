/*
JTSK-320112
Problem 1.2
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <stdio.h>
#define LSB(A) (A & 1) 

int toDecimal(unsigned char a);

int main(int argc,char** argv){
    unsigned char input;
    scanf("%c",&input);
    getchar();
    
    printf("The decimal representation is: %d\n",toDecimal(input));
    printf("The least significant bit is: %d\n",LSB(input));
    
    return 0;
}

//Function to convert to decimal 
int toDecimal(unsigned char a){
    int decimal = 0;
    for (int i=0;i<8;i++){
        decimal+= (a & 1 << i);
    }
    return decimal;
}