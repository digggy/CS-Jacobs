/*
JTSK-320112
Problem 5.1
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include<stdio.h>
#include<stdlib.h>

#include"stack.h"

int main(int argc,char** argv){
   struct stack *mystack;
   mystack = (struct stack *)malloc(sizeof(struct stack));
   init(mystack,0);
   char input='z';
   char option;
   int newel;
   
   while (input!='q'){
      scanf("%c",&option);
      switch (option)
      {
         case 's':
            scanf("%d",&newel);
            push(newel,mystack);
            break;
         case 'p':
            mystack=pop(mystack);
            break;
         case 'e':
            empty(mystack);
            break;
         case 'q':
         input='q';
		printf("Quit\n");
            break;
      }
   }
   return 0;
    
}
