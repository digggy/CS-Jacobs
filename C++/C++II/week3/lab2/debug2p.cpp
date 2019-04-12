/*
CH08-320143
a6p2.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <sstream>
using namespace std;

/*
	Here we have the the break point at line 21 and we can check the value of 
	*odd and we find the *odd++ that is inceasing the pointer.
	We are modifing the element that the pointer is pointing to not the 
	pointer itself to make it work.

*/
void foo(int *array, int n, int *odds)
{
	for (int i = 0; i < n; i++)
		if (array[i] % 2 == 1)
			(*odds)++;
}

class Test
{
  private:
	double *a;
	int n;

  public:
	Test()
	{
		a = NULL;
		n = 0;
	}
	Test(double *a, int n)
	{
		this->n = n;
		if (this->a != NULL)
		{
			delete this->a;
		}
		this->a = new double[n];
		for (int i = 0; i < n; i++)
			this->a[i] = a[i];
	}
	string toString()
	{
		ostringstream ss;
		ss << "Length: " << n << endl
		   << "Elements: ";
		for (int i = 0; i < n; i++)
			ss << a[i] << " ";
		ss << endl;
		return ss.str();
	}
	~Test()
	{
		delete a;
	}
};

int main()
{
	int array[3] = {1, 2, 3};
	int odd_values = 0;
	foo(array, 3, &odd_values);
	cout << "Amount of odd values in the array=" << odd_values << endl;

	Test arr[5];
	double v[3] = {1.2, 2.3, 3.45};
	Test *obj1;
	obj1 = &arr[0];
	Test *obj2 = new Test(v, 3);

	// obj3 was a null pointer so now it points to a object in arr[1]
	// so the command in 83 works now

	Test *obj3 = &arr[1];
	cout << obj1->toString();
	cout << obj2->toString();
	cout << obj3->toString();

	delete obj2;
	/*
		No need to delete the other objects as they will be deleted by the destructor themselves.
		Thus we used the breakpoint at 60 and found that the object was getting deleted twice.
	*/
	return 0;
}
