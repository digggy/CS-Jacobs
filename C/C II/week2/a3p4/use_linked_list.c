/*
JTSK-320112
Problem 3.1
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
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
