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
    double* componentA= new double[3]{1,2,3};
    double* componentB= new double[3]{4,5,8};
    
    //First Vector    
    Vector A;
    cout<<"\nVector A by Default Constructor  : ";
    A.print();

    //Setting new component to the vector
    A.setComponent(componentA);
    cout<<"Vector A After Setting Component : ";
    A.print();
    cout<<"-------------------------------------------"<<endl;

    //Printing all vectors 
    cout<<"Vector A : ";
    A.print();
    cout<<endl;

    //New Copied Vector B
    cout<<"Vector B : ";
    Vector B(A);
    B.print();
    cout<<endl;

    //New Vector C
    Vector C (3,componentB);
    cout<<"Vector C : ";
    C.print();

    //Now Implementing the methods 
    cout<<"-------------------------------------------"<<endl;

    //Vector Norm
    cout<<"Norm of Vector A = ";
    cout<<A.norm()<<endl;
    cout<<endl;

    //Scalar Product
    cout<<"Scalar Product of Vector A & Vector C = ";
    cout<<A.sProduct(C)<<endl;
    cout<<endl;

    //Vector Sum
    cout<<"Sum of Vector A and Vector C = ";
    A.add(C).print();
    cout<<endl;

    //Vector Difference
    cout<<"Difference of Vector A and Vector C = ";
    A.sub(C).print();
    cout<<endl;
        
    return 0;
}

