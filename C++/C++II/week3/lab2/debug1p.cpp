/*
CH08-320143
a6p1.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

/*
	The breakpoint was set on the line 25.
	There was a wrong result because the difference of two unsigned ints 
	is an unsigned int which is not less than 0. So the program opts towards
	the else condition which in turns has a negative difference.
	As unsigned int doesnt have -ve numbers we have the wrong result/weird result. 
*/
#include <iostream>
using namespace std;

int find(int a[], int nr, int el)
{
	for (int i = 0; i <= nr; i++)
		if (a[i] == el)
			return i;
	return -1;
}

unsigned long difference(unsigned long a, unsigned long b)
{
	// Fix is to compare which one is greater and proceed accordingly
	if (a < b)
	{
		return b - a;
	}
	else
	{
		return a - b;
	}
}

int main()
{
	int n, val;
	cout << "n=";
	cin >> n;
	int *v = new int[n];
	cout << "Elements the elements of array:" << endl;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cout << "val=";
	cin >> val;
	int result = find(v, n, val);
	cout << "Position of the searched element in the array=" << result << endl;
	delete v;
	unsigned long x, y;
	x = 550000;
	y = 550005;

	cout << "Difference=" << difference(x, y) << endl;
	return 0;
}
