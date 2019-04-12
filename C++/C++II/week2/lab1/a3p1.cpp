/*
CH08-320143
a3p1.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    //A vector container
    vector<string> words;
    string word;
    cout << "Insert the words :\n";
    //Get the input word
    getline(cin, word);
    while (!(word == "stop"))
    {
        words.push_back(word);
        getline(cin, word);
    }

    //Printing the words with the index
    if (words.size() != 0)
    {
        cout << "\nWith the index operator" << endl;
        for (unsigned int i = 0; i < words.size(); i++)
        {
            if (i == words.size() - 1)
            {
                cout << words[i];
            }
            else
            {
                cout << words[i] << ", ";
            }
        }

        //Declare the iterator for the vector
        cout << "\n\nWith the iterator" << endl;
        vector<string>::const_iterator pos;
        for (pos = words.begin(); pos != words.end(); ++pos)
        {
            cout << *pos << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No elements in the the vector";
    }

    return 0;
}