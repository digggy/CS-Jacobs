/*
JTSK-320112
Problem 5.1
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include<stdio.h>
#include "stack.h"

void push(int item,struct stack *list){
   if (list->count<=11){
      printf("Pushing %d\n",item);
      list->array[list->count]=item;
      list->count++;
   }else
   {
      printf("Pushing Stack Overflow\n");
   }
   
}
struct stack *pop (struct stack *list){
   if (list->count>0){
      list->count--;
      printf("Popping %d\n",list->array[list->count]); 
   }else{
      printf("Popping Stack Underflow\n");
   }   
   return list;
}
void empty(struct stack *list){
   printf("Emptying Stack ");
   while(list->count>0){
      list->count--;
      printf("%d ",list->array[list->count]);
   }
   printf("\n");
}

void isFull(struct stack *list){
   if(list->count==12){
      printf("The stack is full\n");
   }
}
void isEmpty(struct stack *list){
   if(list->count==0){
      printf("The stack is full\n");
   }
}
void init(struct stack *list,unsigned int count){
   list->count=count;
}