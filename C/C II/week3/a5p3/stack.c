/*
JTSK-320112
Problem 5.1
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include<stdio.h>
#include<string.h>

#include "stack.h"

void push(char item[],struct stack *list){
   if (list->count<=19){
      // printf("Pushing %s\n",item);
      strcpy(list->array[list->count],item);
      // printf("%s",list->array[list->count]);
      list->count++;
   }else
   {
      printf("Pushing Stack Overflow\n");
   }
   
}

char *pop(struct stack *list){
   if (list->count>0){
      list->count--;
      return list->array[list->count]; 
   }
   return "Poping Stack Underflow";
}
