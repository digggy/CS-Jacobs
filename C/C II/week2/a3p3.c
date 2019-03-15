/*
JTSK-320112
Problem 3.3
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

struct list
{
    char info;
    struct list *next; /* self reference */
    struct list *prev;
};

void freelist(struct list *my_list);
void print_list(struct list *my_list);
struct list *push_front(struct list *my_list, char value);
struct list *removeElement(struct list *my_list,char val);
void printreverse(struct list *my_list);


int main(int argc, char **argv)
{
    char quit = 'n';
    //variable to control the list
    char input;
    //element for the list
    char element;
    struct list *my_list = NULL;
    char val;
    while (quit != 'q')
    {
        //scanf to ask what to do with the loop
        scanf("%c", &input);
        getchar();
        switch (input)
        {
        case '1':
            //add at the begining
            scanf("%c", &element);
            getchar();
            my_list = push_front(my_list, element);
            break;
        case '2':
            //remove the characters
            scanf("%c", &val); 
            getchar();
            my_list=removeElement(my_list,val);
            break;

        case '3':
            //print the elements
            print_list(my_list);
            break;
        case '4':
            printreverse(my_list);
           break;
        case '5':
            //quit the program and free the memory
            quit = 'q';
            freelist(my_list);
        }
    }

    return 0;
}

//Free the list 
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
        printf("%c ", p->info);
    }
    printf("\n");
}

//Add the element in the front
struct list *push_front(struct list *my_list, char value)
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
    newel->prev =NULL;
    if (my_list!=NULL){
        my_list->prev=newel;
    }
    return newel;
}

//Function to remove an element from the list 
struct list *removeElement(struct list *my_list,char val){
    struct list *current,*prevElem, *nextElem;
    current=my_list;
    prevElem=current->prev;
    nextElem=current->next;
    _Bool status=0;

    //While the current element is not NULL
    while(current!=NULL){
        if(current->info==val){
            status=1;
            if (prevElem==NULL){
                //For the first element
                nextElem->prev=current->prev;
                my_list=nextElem;
            }else if(nextElem==NULL)
            {
                //For the last element
                prevElem->next=current->next;
            }
            else
            {
                prevElem->next=current->next;
                nextElem->prev=current->prev;
            }
        }
        //To the new element 
        current=current->next;
        if (current!=NULL)
        {
            prevElem=current->prev; 
            nextElem=current->next;
        }
                    
    }
    if (status!=1){
        printf("The element is not in the list!\n");
    }
    return my_list;
}

//print the reverse the linked list 
void printreverse(struct list *my_list){
    struct list *p;
    p = my_list;
    while(p->next!=NULL){
        p=p->next;
    }
    do{
        printf("%c ",p->info);
        p=p->prev;
    }while(p!=NULL);
    
    printf("\n");
}
