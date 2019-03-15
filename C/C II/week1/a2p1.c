/*
JTSK-320112
Problem 2.1
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <stdio.h>


int main(int argc,char** argv){
    
    int numbers;
    int counter=0;
    scanf("%d",&numbers);
    
    //Declaration of an array
    float arr[numbers];

    for (int i=0;i<numbers;i++){
        scanf("%f",&arr[i]);
    }
    
    //Using pointer to navaigate to the values 
    //The variable numbers is used to bound the size of the loop 

    for(float* j=arr;*j>0 && numbers>0;j++){
	  counter+=1;
	  numbers-=1;
    }

    printf("Before the first negative value: %d elements\n",counter);


       return 0;
}
