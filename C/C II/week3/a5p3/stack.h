/*
JTSK-320112
Problem 5.1
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#ifndef _STACK_H
#define _STACK_H

struct stack {
   unsigned int count;
   char array[20][30]; // Container
};

void push(char [],struct stack *list);
char *pop(struct stack *list);

#endif
