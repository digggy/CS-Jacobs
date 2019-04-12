/*
CH08-320143
a5p2.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <exception>
#include <string>
using namespace std;

//  Own Exception class
class OwnException : public exception
{
  private:
    string data;

  public:
    OwnException(string input)
    {
        this->data = input;
    }
    virtual const string what()
    {
        return "This is an OwnException";
    }
};

//Function to throw exception
void expHandler(char input)
{
    if (input == '1')
    {
        throw 'e';
    }
    else if (input == '2')
    {
        throw 99;
    }
    else if (input == '3')
    {
        throw false;
    }
    else
    {
        throw OwnException("This is a default case exception");
    }
}

// Main function
int main(int argc, char **argv)
{
    for (char i = '1'; i <= '4'; i++)
    {
        try
        {
            expHandler(i);
        }
        catch (int e)
        {
            cerr << "Exception caught in main: " << e << endl;
        }
        catch (char e)
        {
            cerr << "Exception caught in main: " << e << endl;
        }
        catch (bool e)
        {
            cerr << "Exception caught in main: " << e << endl;
        }
        catch (OwnException &e)
        {
            cout << "Exception caught in main: " << e.what() << endl;
        }
    }
    return 0;
}
