/*
JTSK-320112
Problem 6.5
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    char filename[n][50];

    FILE *out;
    out=fopen("output.txt","wb");
    
    if(!out){
        printf("Unable to create output.txt file");
    }

    for (int i=0;i<n;i++){
        fgets(filename[i],50,stdin);
        filename[i][strlen(filename[i])-1]='\0';             
    }

    printf("Concating the content of 3 files ...\n");
    printf("The result is:\n");
    for (int i=0;i<n;i++){
        FILE *temp;
        char buffer[64];
        char newline[] ="\n";

        //Opening the file in binary mode
        temp=fopen(filename[i],"rb");
        
        fseek(temp,0,SEEK_END);
        int size=ftell(temp);
        fseek(temp,0,SEEK_SET);
        
        fread(buffer,sizeof(char),size,temp);
        buffer[size]='\0';

        printf("%s\n",buffer);
        fwrite(buffer,sizeof(char),size,out);
        
        
        fclose(temp);

        fwrite(newline,sizeof(char),1,out);
    }
    printf("The result was written into output.txt\n");
    return 0;

}