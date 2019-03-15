/*
JTSK-320112
Problem 5.1
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc,char** argv){
    FILE *fp;
    char ch;
    char filename[50];
    int count=0;
    int status=0;

    scanf("%s",filename);
    getchar();

    fp=fopen(filename,"r");
    //Check if the file is present
    if (!fp){
        fprintf (stderr , " Cannot open file !\n");
        exit (1) ;
    }
    ch=getc(fp);
    //Loop and find the number of words
    while(ch!=EOF){
        if (ch==' '||ch==','||ch=='?'||ch=='!'||ch=='.'||ch=='\t'||ch=='\r'||ch=='\n'){
            if (status==0){
                count+=1;
            }
            status=1;
        }else{
            status=0;
        }
        ch=getc(fp);
    }
    printf("The file contains %d words.\n",count);
    fclose(fp);
    return 0;
}
