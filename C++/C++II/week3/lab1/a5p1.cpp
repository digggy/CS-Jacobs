/*
CH08-320143
a5p1.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <vector>
#include <exception>
using namespace std;

int main(int argc, char **argv)
{
    vector<char> alphabet;

    //Assigning the '@' for 15 the elements in the vector
    alphabet.assign(15, '@');

    // Try catch block
    try
    {
        alphabet.at(15);
    }
    catch (out_of_range &e)
    {
        cerr << e.what() << endl;
    }
    catch (...)
    {
        cerr << "Default Exception";
    }

    return 0;
}
