/*
JTSK-320112
Problem 5.2
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#ifndef _STACK_H
#define _STACK_H

struct stack {
   unsigned int count;
   int array[12]; // Container
};

void push(int item,struct stack *list);
void pop (struct stack *list);
void empty(struct stack *list);
void init(struct stack *list,unsigned int count);
void printbinary(struct stack *mystack,int ncopy);

#endif
