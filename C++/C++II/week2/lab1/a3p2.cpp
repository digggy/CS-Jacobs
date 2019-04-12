/*
CH08-320143
a3p2.cpp
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
    while (!(word == "STOP"))
    {
        words.push_back(word);
        getline(cin, word);
    }

    if (words.size() >= 4)
    {
        swap(words[1], words[3]);
    }
    else
    {
        cout << "One of them or both do not exist" << endl;
    }
    //Replacing the last elements with "?"
    if (words.size())
    {
        words[words.size() - 1] = "?";
    }
    else
    {
        cout << "Sorry no elements in the Vector :( \n";
        exit(0);
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
                cout << words[i] << " ; ";
            }
        }

        //Declare the iterator for the vector
        cout << "\n\nWith the iterator" << endl;
        vector<string>::const_iterator pos;
        for (pos = words.begin(); pos != words.end(); ++pos)
        {
            if (pos == (words.end() - 1))
            {
                cout << *pos;
            }
            else
            {
                cout << *pos << " - ";
            }
        }
        cout << endl;

        //Declare the iterator for the vector
        cout << "\n\nReverse order with the iterator" << endl;
        vector<string>::const_iterator back;
        for (back = words.end() - 1; back != words.begin() - 1; back--)
        {
            cout << *back << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No elements in the the vector";
    }

    return 0;
}