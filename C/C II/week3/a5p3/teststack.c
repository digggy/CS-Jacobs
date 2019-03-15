/*
JTSK-320112
Problem 5.1
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"stack.h"

int checkpalindrome(char (*word)[30],struct stack *mystack);

int main(int argc,char** argv){
   struct stack *mystack;
   mystack = (struct stack *)malloc(sizeof(struct stack));
   char sentence[1000];
   char word[20][30];

   scanf("%[^\n]",sentence);
   getchar();
   while(strcmp(sentence,"exit")){
   
      mystack->count=0;   
      //Seperating the words in sentence
      int j=0,k=0;
      for (int i=0; sentence[i]!='\0';i++){
         if(sentence[i]==' '){
            word[j][k]='\0';         
            // printf("Found Space j :%d k :%d\n",j,k);
            j++;
            k=0;
         }else{
            word[j][k]=sentence[i];
            k++;      
         }
      }
      word[j][k]='\0';

      //Pushing into the stack of words
      for (int i=0;i<=j;i++){
            push(word[i],mystack);
      }

      //calling the fuction checkpalindrome
      if(checkpalindrome(word,mystack)){
         printf("The sentence is palindromic by words!\n");
      }else{
         printf("The sentence is not palindromic by words!\n");
      }
      
      //Asking for another input
      scanf("%[^\n]",sentence);
      getchar();
   }

   free(mystack);

   return 0;
    
}

//Poping and Comparing with original array 
int checkpalindrome(char (*word)[30],struct stack *mystack){
   int count=0;
   while(mystack->count>0){
      if(strcmp(pop(mystack),word[count])){
         return 0;
      }
      count++;
   }
   return 1;
return 0;
}