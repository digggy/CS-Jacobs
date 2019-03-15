/*
JTSK-320112
Problem 1.7
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <stdio.h>
#include <math.h>

unsigned char set3bits(unsigned char input, int a, int b, int c);
void findbinary(unsigned char input);

int main(int argc, char **argv)
{
    //Declaring the unsigned char
    unsigned char input;
    int one, two, three;

    //Asking the input 
    scanf("%c", &input);
    scanf("%d", &one);
    scanf("%d", &two);
    scanf("%d", &three);
    
    //The decimal representation
    printf("The decimal representation is: %d\n",input);
    
    //The binary representation
    printf("The binary representation is: ");
    findbinary(input);    
    
    //The binary representation after setting the bits
    printf("After setting the bits: ");
    findbinary(set3bits(input, one, two, three));

    return 0;
}

//Function to se the bits 
unsigned char set3bits(unsigned char input, int a, int b, int c)
{
    
    for (int i = 0; i < 8; i++)
    {
        int val=1;
        for (int j = 1; j <= i; j++)
        {
            val *= 2;
        }

        if ((i == a) || (i == b) || (i == c))
        {
            input = (input | val);
        }
    }

    return input;
}

//Function to find the binary of a unsigned using bit mask and bitwise
void findbinary(unsigned char input){
    for (int i = 0; i < 8; i++){
        int val=1;
        for(int j=7;j>i;j--){
            val*=2;
        }
         
        if(input&val){
            printf("1");
        }else
        {
            printf("0");
        }
        
    }
    printf("\n");
}