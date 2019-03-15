/*
JTSK-320112
Problem 4.2
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void strupr(char * str);
void strlwr(char * str);
void strchange(char * str);
void quit(char * str);

int main(int argc,char** argv){
    char str[200];
    int choice=-1;
    void (*func[4])(char*);
    scanf ("%[^\n]%*c", str);

    //Assiging the pointer functions
    func[0]=strupr;
    func[1]=strlwr;
    func[2]=strchange;
    func[3]=quit;

    while(choice!=4){
        scanf("%d",&choice);
        func[choice-1](str);
    }
    
    return 0;
}
//Function to convert to Upper characters 
void strupr(char * str ){
    char new[200];
    int c=0;
    strcpy(new,str);
    while(new[c]!='\0'){
        if (new[c] >= 'a' && new[c] <= 'z') {
         new[c] = new[c] - 32;
      }
      c++;
    }
    printf("%s\n",new);
}
//Function to convert to Lower characters 
void strlwr(char * str){
char new[200];
    int c=0;
    strcpy(new,str);
    while(new[c]!='\0'){
        if (new[c] >= 'A' && new[c] <= 'Z') {
         new[c] = new[c] + 32;
      }
      c++;
    }
    printf("%s\n",new);
}

//Function to convert to reverse the case of characters 
void strchange(char * str){
char new[200];
    int c=0;
    strcpy(new,str);
    while(new[c]!='\0'){
        if (new[c] >= 'A' && new[c] <= 'Z') {
         new[c] = new[c] + 32;
      }else if (new[c] >= 'a' && new[c] <= 'z') {
         new[c] = new[c] - 32;
      }
      c++;
    }
    printf("%s\n",new);
}

//Function to quit
void quit(char * str){
    exit(0);
}
