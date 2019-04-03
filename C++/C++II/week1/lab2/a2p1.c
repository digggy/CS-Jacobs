/*
CH08-320143
a2p1.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

class Complex
{
    private:
    int real;
    int imaginary;

    public:
    Complex();
    Complex(int, int);

    double getmagnitude() const;

    //Operator overload methods
    Complex operator+(const Complex &);
    Complex operator-(const Complex &);
    Complex operator*(const Complex &);
    Complex operator=(const Complex &);
    bool operator>(const Complex &);
    bool operator<(const Complex &);


    friend ostream &operator<<(ostream &, const Complex &);
    friend istream &operator>>(istream &, Complex &);
};

Complex::Complex()
{
    real = imaginary = 0;
}

Complex::Complex(int r, int i)
{
    //paramatic constructor
    real = r;
    imaginary = i;
}

double Complex::getmagnitude() const {
    double magnitude;
    magnitude= sqrt(pow(real,2)+pow(imaginary,2));
    return magnitude;
}

//Operator overload to multiply
Complex Complex::operator*(const Complex &input)
{
    Complex mul;
    mul.real = real * input.real - imaginary * input.imaginary;
    mul.imaginary = real * input.imaginary + imaginary * input.real;
    return mul;
}

//Operator overload to add
Complex Complex::operator+(const Complex &input)
{
    Complex num;
    num.real = real + input.real;
    num.imaginary = imaginary + input.imaginary;
    return num;
}

//Operator overload to substract
Complex Complex::operator-(const Complex &input)
{
    Complex sub;
    sub.real = real - input.real;
    sub.imaginary = imaginary - input.imaginary;
    return sub;
}

//Less than overload
bool Complex::operator<(const Complex &input){    
    if (this->getmagnitude()<input.getmagnitude()){
        return true;
    }else{
        return false;
    }
}
//Greater than overload
bool Complex::operator>(const Complex &input){
    if (this->getmagnitude()>input.getmagnitude()){
        return true;
    }else{
        return false;
    }
}

//Assignment operator
Complex Complex::operator=(const Complex &input)
{
    real = input.real;
    imaginary = input.imaginary;
    return *this;
}

//Output  operator overload
ostream &operator<<(ostream &out, const Complex &input)
{
    if (input.imaginary)
    {
        out << noshowpos << input.real << showpos << input.imaginary << "i" << endl; //using showpos to print '+' in required conditions
    }
    else
    {
        out << noshowpos << input.real << showpos << endl;
    }
    return out;
}

// Input operator overload
istream &operator>>(istream &in, Complex &num)
{
    in >> num.real >> num.imaginary;
    return in;
}


//Template function declaration
template <class T>
T array_min(T arr[], int num)
{
    T min = arr[0];
    for (int i = 1; i < num; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }

    return min;
}

int main(int argc , char** argv)
{
    //Int Array
    int arra[] = {5, 4, 3, 2, 1, -10};
    //double Array
    double arrb[] = {0.001, 0.003, -0.213, 0.456, -0.21, 0.55};
    //Complex Array
    Complex arrc[]={Complex(5,2),Complex(2,3),Complex(4,2),Complex(-0,1)};
    
    //Printing the minimums
    cout<<"\nMinimums are : \n\n";
    cout << "In Int    Arr is  : " << array_min(arra, 6) << endl;
    cout << "In Double Arr is  : " << array_min(arrb, 6) << endl;
    cout << "In Complex Arr is : " << array_min(arrc, 4) << endl;

    return 0;
}