/*
JTSK-320112
Problem 6.2
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include<stdio.h>
#include "stack.h"

//Push elements to the stack 
void push(int item,struct stack *list){
   if (list->count<=11){
      list->array[list->count]=item;
      list->count++;
   }else
   {
      printf("Pushing Stack Overflow\n");
   }
   
}
//Pop the elements form the stack
void pop (struct stack *list){
   if (list->count>0){
      list->count--;
      printf("%d",list->array[list->count]); 
   }else{
      printf("Popping Stack Underflow\n");
   }   
}
//Clear stack
void empty(struct stack *list){
   printf("Emptying Stack ");
   while(list->count>0){
      list->count--;
      printf("%d ",list->array[list->count]);
   }
   printf("\n");
}

//Init stack
void init(struct stack *list,unsigned int count){
   list->count=count;
}

//Function to clear the stack
void printbinary(struct stack *mystack,int ncopy){
   printf("The binary representation of %d is ",ncopy);
   while(mystack->count>0){
      pop(mystack);
   }
   printf(".\n");
}