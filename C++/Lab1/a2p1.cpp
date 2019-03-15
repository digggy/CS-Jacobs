/*
CH08-320142
Problem 2.1.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include<iostream>
#include<string>
using namespace std;

int myfirst(int *array,int size);
double myfirst(double *array,int size);
char myfirst(char *array,int size);

int main(int argc,char** argv){
    int a[]={1,2,3,4};        
    double b[]={1.1,2,3.1415,6};
    char str[]={'a','p','p','l','e'};
    
    myfirst(a,4);
    myfirst(b,4);
    myfirst()
    return 0;
}

/*Determines and returns the first positive and odd valuefrom the array. 
If no such element exists then −1 is returned*/

int myfirst(int *array,int size){
    for (int i=0;i<size;i++){
        if (array[i]>0 || array[i] % 2 == 1 ){
	      return array[i];
        }
    }
    return -1;
}

/*Determines and returns the first positive element which doesn't have a 
fractional part.If no such element exists then −1.1 is returned*/

double myfirst(double *array,int size){
    for (int i=0;i<size;i++){
        if (array[i]>0 || array[i]/(int)array[i] == 1 ){
	      return array[i];
        }
    }
    return -1.1;
}

/* Determines and returns the first element which is a vowel otherwise  
If no vowels are present in the array then the character ’0’ is returned */

char myfirst(char *array,int size){
     for (int i=0;i<size;i++){
        if (array[i]=='a'|| array[i]=='e'|| array[i]=='i'|| array[i]=='o'||array[i]=='u'){
	     return array[i];
        } 
    }
    return '0'; 
}


