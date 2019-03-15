/*
JTSK-320112
Problem 1.6
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <stdio.h>
void findbinary(unsigned char input);

int main(int argc, char **argv)
{
    unsigned char input;
    scanf("%c", &input);

    printf("The decimal representation is: %d\n", input);
    
    printf("The binary representation is: ");
    //Function call
    findbinary(input);


    return 0;
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