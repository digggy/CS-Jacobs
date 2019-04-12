/*
CH08-320143
a4p5.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    ifstream input;
    map<unsigned long, string> database;

    input.open("data.txt", ios::in);
    //Checking for errors
    if (!input.good())
    {
        cerr << "Error oopening the file" << endl;
        exit(0);
    }
    while (!input.eof())
    {
        unsigned long matriculation;
        string fname;
        string lname;
        input >> matriculation >> fname >> lname;
        database[matriculation] = fname + ' ' + lname;
    }
    input.close();
    unsigned long usrInput;
    string usrChioce = "n";

    cout << "Welcome to the database\n";
    cout << "Search with Matriculation No\n";
    while (usrChioce != "y")
    {
        cout << "\nWrite the matriculation number\n";
        cin >> usrInput;
        if (database.find(usrInput) != database.end())
        {
            cout << database[usrInput] << endl;
        }
        else
        {
            cout << "Matriculation number not found!\n";
        }
        cout << "\nDo you want to exit (Y/N)?";
        cin >> usrChioce;
        //Converting Case to lower
        transform(usrChioce.begin(), usrChioce.end(), usrChioce.begin(), ::tolower);
    }

    return 0;
}