/*
JTSK-320112
Problem 1.4
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <stdio.h>
#define INTERMEDIATE

int main(int argc,char** argv){
    int size;
    int scalarproduct=0;

    scanf("%d",&size);
    int vectora[size];
    int vectorb[size];
    
    //Taking inputs for the vectors 
    for (int i=0;i<size;i++){
        scanf("%d",&vectora[i]);
    }

    for (int i=0;i<size;i++){
        scanf("%d",&vectorb[i]);
    }

    //Checking if the INTERMEDIATE is defined
    #if defined(INTERMEDIATE)
        printf("The intermediate product values are:\n");
    #endif

    //Loop to find the scalar and the intermediate product 
    for (int i=0;i<size;i++){
        int intermediate=vectora[i]*vectorb[i];
    
        #if defined(INTERMEDIATE)
            printf("%d\n",intermediate);
        #endif

        scalarproduct+=intermediate;
    }

    printf("The scalar product is: %d\n",scalarproduct);

    return 0;
}
