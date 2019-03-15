/*
JTSK-320112
Problem 3.1
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
void freelist(struct list *my_list)
{
    struct list *nextelem;
    while (my_list != NULL)
    {
        nextelem = my_list->next;
        free(my_list);
        my_list = nextelem;
    }
}

//print the elements of the list
void print_list(struct list *my_list)
{
    struct list *p;
    for (p = my_list; p; p = p->next)
    {
        printf("%d ", p->info);
    }
    printf("\n");
}

//Add the element in the front
struct list *push_front(struct list *my_list, int value)
{
    struct list *newel;
    newel = (struct list *)malloc(sizeof(struct list));
    if (newel == NULL)
    {
        printf(" Error allocating memory \n");
        return my_list;
    }
    newel->info = value;
    newel->next = my_list;
    return newel;
}
//Add the element in the back
struct list *push_back(struct list *my_list, int value)
{
    struct list *cursor, *newel;
    cursor = my_list;
    newel = (struct list *)malloc(sizeof(struct list));
    if (newel == NULL)
    {
        printf(" Error allocating memory \n");
        return my_list;
    }
    newel->info = value;
    newel->next = NULL;
    if (my_list == NULL)
        return newel;
    while (cursor->next != NULL)
        cursor = cursor->next;
    cursor->next = newel;
    return my_list;
}

//Remove the first element
struct list *remove_first(struct list *my_list)
{
    struct list *newlist = NULL;
    if (my_list != NULL)
    {
        newlist = my_list->next;
        free(my_list);
        return newlist;
    }
    else
    {
        return my_list;
    }
}
