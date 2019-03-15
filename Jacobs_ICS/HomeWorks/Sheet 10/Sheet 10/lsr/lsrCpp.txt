#include<iostream>
#include <dirent.h>
#include<string>
using namespace std;

/*
This program d recursively shows the content of the current working directory if no arguments
are passed to the main() function of the program. Otherwise, starts a recursive listing for each of
the arguments that are passed to the main() function.
*/

void search (char* name);
int main (int charc , char *charv[]) {
    char* root=new char[1]{'.'};
    if (charc==1){
        search(root);
        delete root;
         return 0;
    }else{
        //if the argc is more than 1
        for (int i =1;i<charc;i++){
            //Calling a search function in main   
            search(charv[i]);
        }
    }
    return 0;
}

//This is the search function 
void search (char* name){
    DIR *dir;
    char* fname;
    string loc,dirName;
    struct dirent *current;

    dir=opendir(name);

    //Check if the dir is NULL 
    if (dir!=NULL){
        
        while((current=readdir(dir))!=NULL ){
            //assign fname with the current->d_name
            fname=current->d_name;
            
            //if the file starts with . then neglect printing it 
            if (current->d_name[0] != '.'){

                if (name[0]=='.'&& name[1]=='\0'){
                    cout<<fname<<endl;
                    //location of contents (files) of that directory from current directory 
                    loc=fname;
                }else{
                    cout<<name<<"/"<<fname<<endl;
                    if (current->d_type== DT_DIR){
                        //Initial location of the file is name
                        loc=name;
                        //dirName is the filename of a file that is a directory
                        dirName=fname;
                        //loc is location of contents (files) of that directory from current directory 
                        loc=loc+"/"+dirName;
                    }
                }
            }
            //if the file is a directory then we have to read if that directory has other files in itself
            if (current->d_type== DT_DIR && current->d_name[0] != '.' ){

                //The below steps copy a string to a pointer 
                //Copies the loc to char pointer nloc
                char * nloc = new char[loc.size() + 1];
                copy(loc.begin(), loc.end(), nloc);
                nloc[loc.size()] = '\0';

                //Recusively go and read the files in directory
                search(nloc);   
                delete nloc;
            }
        }

    }else{
        //If the name doesnt match the directory or if dir is NULL
        cout<<"Error opening the Directory : "<<name<<endl;
    } 
    //Close the dir
    closedir(dir);
    }
