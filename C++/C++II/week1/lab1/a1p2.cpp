/*
CH08-320143
a1p1.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n;
    char fname[100];
    char *block;
    int size;

    //Number of files
    cout << "Input the number of files" << endl;
    cin >> n;

    ifstream in;
    ofstream out;

    //Output file
    out.open("concat.txt", ios::out | ios::binary);
    for (int i = 0; i < n; i++)
    {
        //User inputs the file name
        cout << "Input filename - " << i + 1 << endl;
        cin >> fname;

        //Opening the file with the crusor in the end
        in.open(fname, ios::binary | ios::ate);
        //Checking if the file opens fine succesfully
        if (!in.good())
        {
            cerr << "Error Opening the file" << endl;
        }

        //One plus to add a new line in last of every file
        size = 1 + in.tellg();
        block = new char[size];

        in.seekg(0, ios::beg);
        in.read(block, size);

        //setting the last char as newline
        block[size - 1] = '\n';

        //Writting in the output file
        out.write(block, size);

        //Closing the imput file
        in.close();
        //Freeing memory of block
        delete[] block;
    }
    // Closing the output file
    out.close();
    return 0;
}