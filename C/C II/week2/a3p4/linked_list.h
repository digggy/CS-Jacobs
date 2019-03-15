/*
JTSK-320112
Problem 3.1
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H
struct list
{
    int info;
    struct list *next; /* self reference */
};

void print_list(struct list *my_list);
void freelist(struct list *my_list);
struct list *push_front(struct list *my_list, int value);
struct list *push_back(struct list *my_list, int value);
struct list *remove_first(struct list *my_list);

#endif
