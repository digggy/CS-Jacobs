/*
JTSK-320112
Problem 1.5
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <stdio.h>

int main(int argc, char **argv)
{

    unsigned char input, copy;
    int counter;

    scanf("%c", &input);
    copy = input;

    printf("The decimal representation is: %d\n", input);
    printf("The backwards binary representation is: ");

    //Finding the length of digits of the binary number
    for (int i = 0; i < 8; i++)
    {
        if (copy & 1)
        {
            counter = i;
        }
        copy = copy >> 1;
    }
    //Printing the number
    for (int i = 0; i <= counter; i++)
    {
        (input & 1) ? printf("1") : printf("0");
        input = input >> 1;
    }
    printf("\n");

    return 0;
}
