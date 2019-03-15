/*
JTSK-320112
Problem 3.1
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char **argv)
{
    char quit = 'n';
    //variable to control the list
    char input;
    //element for the list
    int element;
    struct list *my_list = NULL;

    while (quit != 'q')
    {
        //scanf to ask what to do with the loop
        scanf("%c", &input);
        switch (input)
        {
        case 'a':
            //add at the end
            scanf("%d", &element);
            my_list = push_back(my_list, element);
            break;
        case 'b':
            //add at the begining
            scanf("%d", &element);
            my_list = push_front(my_list, element);
            break;
        case 'p':
            //print the elements
            print_list(my_list); /* code */
            break;
        case 'r':
            //remove the fist element
            my_list = remove_first(my_list);
            break;
        case 'q':
            //quit the program and free the memory
            quit = 'q';
            freelist(my_list);
        }
    }

    return 0;
}

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
