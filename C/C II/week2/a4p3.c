/*
JTSK-320112
Problem 4.3
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include<stdio.h>
#include<stdlib.h>

void printarray(int* arr,int size);
int ascend ( const void *va , const void * vb );
int descend ( const void *va , const void * vb );


int main(int argc,char** argv){
    int size;
    char command;

    int (*comp[2])(const void *,const void *);  
    comp[0]=ascend;
    comp[1]=descend;

    scanf("%d",&size);
    //Declaring an array
    int arr[size];
    
    //Getting the elements  of an array 
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    getchar();

    while (command!='e'){
        scanf("%c",&command);
        getchar();

        if (command=='a'){
                qsort(arr,size,sizeof(arr[0]),comp[0]);
                printarray(arr,size);
            }else if(command=='d'){
                qsort(arr,size,sizeof(arr[0]),comp[1]);
                printarray(arr,size);
            }else if(command=='e'){
                exit(0);
            }
            else{
                printf("Press e to Exit \n");
            }
    }

    return 0;
}

int ascend ( const void *va , const void * vb ) {
    const int * a = ( const int *) va ;
    const int * b = ( const int *) vb ;
    if (* a < *b ) return -1;
    else if (* a > * b) return 1;
    else return 0;
}

int descend ( const void *va , const void * vb ) {
    const int * a = ( const int *) va ;
    const int * b = ( const int *) vb ;
    if (* a < *b ) return 1;
    else if (* a > * b) return -1;
    else return 0;
}

void printarray(int* arr,int size){

    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}