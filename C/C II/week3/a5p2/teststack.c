/*
JTSK-320112
Problem 5.2
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include<stdio.h>
#include<stdlib.h>

#include"stack.h"

int main(int argc,char** argv){
   struct stack *mystack;
   mystack = (struct stack *)malloc(sizeof(struct stack));
   
   int newel;
   int number;

   //Asking for the decimal number 
   scanf("%d",&number);
   int ncopy=number;

   while (number>0){
      newel=number%2;
      number=number/2;
      push(newel,mystack);
   }
   printbinary(mystack,ncopy);
   return 0;
    
}

