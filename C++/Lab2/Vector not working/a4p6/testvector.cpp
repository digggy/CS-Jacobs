/*
CH08-320142
Problem 4.6.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <string>
#include"Vector.h"
using namespace std;

int main (int argc,char** argv){
    double* com= new double[3]{1,2,3};
    Vector vec (3,com);
    vec.print();
    vec.add(vec).print();
    cout<<vec.norm()<<endl;
    
    cout<<vec.sProduct(vec)<<endl;
    return 0;
}

