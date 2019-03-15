/*
JTSK-320112
Problem 6.4
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXCHAR 50

struct account{
    char username[MAXCHAR];
    int size;
    struct account *next;
};

void dispose_list( struct account *my_list);

int main(){
    FILE *fp;
    int count=0;
    char filename[50];
    char username[50];
    char password[50];
    char line[MAXCHAR];
    struct account *all=NULL;

     scanf("%[^\n]",filename);
     getchar();

    fp=fopen(filename,"r");
    
    //Error opening the file
    if (!fp){
        printf("Error Opening the file.\n");
        exit(0);
    }

    //Put the username in the linked list
    while(fgets(line,MAXCHAR,fp)!=NULL){
        if (count % 2==0){
            struct account *newel,*current;

            newel=(struct account*)malloc(sizeof(struct account));
            current=(struct account*)malloc(sizeof(struct account));

            current=all;
            
            line[strlen(line)-1]='\0';

            strcpy(newel->username,line);
            newel->size=ftell(fp);
            newel->next=NULL;

            if (all==NULL){
                all=newel;

            }else{
                while(current->next!=NULL){
                    current=current->next;
                }
                current->next=newel;
            }
        }
        count++;
    }

    while(strcmp(username,"exit")){
        
        //Asking the user the username and password
        int status=0;

        scanf("%[^\n]",username);
        getchar();        
        if (strcmp(username,"exit")!=0){
            scanf("%[^\n]",password);
            getchar();
            struct account *current;
            current=(struct account*)malloc(sizeof(struct account));
            current=all;

            //Going throught the linked list for username search
            while(current!=NULL){
                if (strcmp(username,current->username)==0){
                    status=1;
                    char pass[50];
                    fseek(fp,current->size,SEEK_SET);
                    fscanf(fp,"%s",pass);
                    if (strcmp(pass,password)==0){
                        printf("Access to user %s is granted.\n",username);
                    }else
                    {
                        printf("Access to user %s is denied.\n",username);
                    }
                    
                }
                current=current->next;
            }
            //If there is no username
            if(!status){
                printf("No Username Found\n");
            }

        }
    }
    printf("Exiting ...\n");
    //Free memory form the linked list
    dispose_list(all);
    //Closing file
    fclose(fp);

    return 0;

}


//Free the memory
void dispose_list( struct account *my_list){
    struct account * nextelem ;
    while ( my_list != NULL ) {
        nextelem = my_list -> next ;
        free ( my_list ) ;
        my_list = nextelem ;
    }
}