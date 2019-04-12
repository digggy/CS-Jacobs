/*
CH08-320143
a4p1.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    vector<char> alphabet;

    for (int i = 0; i < 26; i++)
    {
        char send = (char)(i + 97);
        alphabet.push_back(send);
    }
    //Printing the initial
    cout << "\nInitial printing\n";
    vector<char>::iterator pos;
    for (pos = alphabet.begin(); pos != alphabet.end(); pos++)
    {
        cout << *pos << " ";
    }
    cout << "\nReversing and printing\n";
    reverse(alphabet.begin(), alphabet.end());

    for (pos = alphabet.begin(); pos != alphabet.end(); pos++)
    {
        cout << *pos << " ";
    }
    //Adding a 'f' at the last of the vector
    alphabet.push_back('f');

    // Replacing 'f' with '$'
    replace(alphabet.begin(), alphabet.end(), 'f', '$');
    cout << "\nAdding,Replacing and printing\n";
    //Printing the element in the vector out
    for (pos = alphabet.begin(); pos != alphabet.end(); pos++)
    {
        cout << *pos << " ";
    }
    cout << "\n"
         << endl;

    return 0;
}
