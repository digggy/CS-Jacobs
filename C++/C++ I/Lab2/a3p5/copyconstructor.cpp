/*
CH08-320142
Problem 3.5.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <cstring>  // standard C string.h header file

using namespace std;

/*
	Naive string: the goal is to illustrate how copy constructors 
	should be handled. See also charbuffer.cpp
*/

class NaiveString {
private:
	char *str;
public:
	NaiveString(const char*);
	NaiveString(const NaiveString&);
	~NaiveString();
	void update(char, char);
	void print();
};

NaiveString::NaiveString(const char* t) {
          cout<<"Constructor Called"<<endl;
	str = new char[strlen(t) + 1];
	strcpy(str, t);
}

/* 
	Copy constructor: creates a new instance of 
	naive string starting from an existing one 
*/

NaiveString::NaiveString(const NaiveString& src) {
	cout<<"Copy constructor called"<<endl;
	str = new char[strlen(src.str) + 1];
	strcpy(str, src.str);
	// please note that we can access src.str even if it is private
	// as we are inside the NaiveString class
}

NaiveString::~NaiveString(){
        cout<<"Destructor Implemented"<<endl;
        delete [] str;
}

/* replaces occurrences of oldchar by newchar */
void NaiveString::update(char oldchar, char newchar) {
	unsigned int i;
	for (i = 0; i < strlen(str); i++) 
		if (str[i] == oldchar)
			str[i] = newchar;
}

void NaiveString::print() {
	cout << str << endl;
}

void funcByVal(NaiveString s) {
	cout << "funcbyval() being called" << endl;
	s.update('B', 'C');
	s.print();
}

void funcByRef(NaiveString& s) {
	cout << "funcbyref() being called" << endl;
	s.update('B', '$');
	s.print();
}

int main(int argc, char** argv)
{
	NaiveString a("aBcBdB"); //First Instance
	a.print();
	cout << "About to call funcbyval()" << endl;
	funcByVal(a);
	a.print();
	NaiveString b("xBxBxB"); //Second Instance
	b.print();
	cout << "About to call funcbyref()" << endl;
	funcByRef(b);
	b.print();
	return 0;
}
