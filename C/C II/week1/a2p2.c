/*
JTSK-320112
Problem 2.2
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv){
    char stringa[100],stringb[100];
    char *stringc;
    scanf("%[^\n]",stringa);
    getchar();

    scanf("%[^\n]",stringb);
    getchar();
    
    int lengtha=0;
    int lengthb=0;
    //finding the length of string a
    while (stringa[lengtha] !='\0'){
     lengtha++;
    }  
    //finding the length of string b
    while (stringb[lengthb] !='\0'){
     lengthb++;
    }  
    
    //determining the length of output string
    int tlength=lengtha+lengthb;
    //Allocating memory to string c
    stringc = (char *) malloc(tlength*sizeof(char));

    //counter to keep the track of index to add a character in array
    int counter=0;
    for(int i=0;i<lengtha;i++){
    stringc[counter]=stringa[i];
    counter+=1;
    }
    
    for(int i=0;i<lengthb;i++){
    stringc[counter]=stringb[i];
    counter+=1;
    };
    
    printf("Result of concatenation: %s\n",stringc);
    
    //freeing memory
    free(stringc);

    return 0;
}
