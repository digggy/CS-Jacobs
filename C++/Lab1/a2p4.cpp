/*
CH08-320142
Problem 2.4.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <string>
#include <ctime>
#include<cstdlib>
using namespace std;

string replaceVowel(string word);

int main (int argc,char** argv){
    
    string words[] ={"computer","television",
    "keyboard","magazine","book","alienware",
    "university","examinations","protein",
    "backspace","suit","gameofthrones",
    "winter","programming","materials"};
    
    srand(static_cast<unsigned int>(time(0)));
    string userInput="";
    string word;
    int count;    

    cout << "<< Welcome To GuessGame >>"<<endl;
    cout<<endl;
    
    while (userInput!="quit"){
        count=1; // reseting count to 1 
        word=words[(rand() % 15)]; //taking a random word from words array
        cout<<replaceVowel(word)<<endl; 
        while (userInput!=word && userInput!="quit"){ 
            cin>>userInput; 
            if (userInput==word){
                cout<<"Congratulations you guessed it right in "<< count << " try." <<endl; 
            } else {
                count+=1; //increasing count if the user fails to guess right
            }
        }
        if (userInput!="quit") {
           cout<<">> Do you want to play again ? "<<endl; 
           cin>>userInput;
        }
    }
    return 0;
    
}

//function to replace the vowels from the word 
string replaceVowel (string word){
    for (unsigned int i=0;i<word.length();i++){
        if (word[i]=='a'|| word[i]=='e'|| word[i]=='i'||word[i]=='o'|| word[i]=='u'||
         word[i]=='A'|| word[i]=='E'|| word[i]=='I'||word[i]=='O'|| word[i]=='U'){    
            word[i]='_';
        } 
    }
    return word;
}

