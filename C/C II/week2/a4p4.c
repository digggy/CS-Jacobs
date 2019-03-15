/*
JTSK-320112
Problem 4.4
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person {
    char name[30];
    int age;
};

void print_persons(struct person *list,int num);
void swap(struct person *xp, struct person *yp);
int age_comp(struct person *list,int pos);
int str_comp(struct person *list,int pos);
void bubbleSort(struct person *list, int n,int (*func)(struct person *list,int pos));

int main(int argc,char** argv){
    int num;
    scanf("%d",&num);
    struct person list[num];

    //Getting the input for the struct
    for(int i=0;i<num;i++){
        scanf("%s",list[i].name);
        scanf("%d",&list[i].age);
    }

    bubbleSort(list,num,str_comp);
    print_persons(list,num);
    
    bubbleSort(list,num,age_comp);
    print_persons(list,num);

    return 0;
}

//Function to swap the structs types

void swap(struct person *xp, struct person *yp) 
{ 
    struct person temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

//Function to print the persons
void print_persons(struct person *list,int num){
    for(int i=0;i<num;i++){
        printf("{%s,",list[i].name);
        printf(" %d}; ",list[i].age);
    }
    printf("\n");
}

//Bubble Sort
void bubbleSort(struct person *list, int n,int (*func)(struct person *list,int pos)) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
       for (j = 0; j < n-i-1; j++)  
           if (func(list,j)) 
              swap(&list[j], &list[j+1]);
            
}

//Name comparision Function
int str_comp(struct person *list,int pos){
    if ((strcmp(list[pos].name,list[pos+1].name))==0)
    {
        return age_comp(list,pos);
    }
    else if (strcmp(list[pos].name,list[pos+1].name)>0)
    {
        return 1;
    }
    return 0;
}

//Age comparision function
int age_comp(struct person *list,int pos){
    if (list[pos].age>list[pos+1].age){
        return 1;
    }else if(list[pos].age==list[pos+1].age){
        return str_comp(list,pos);
    }
    return 0;
    
}