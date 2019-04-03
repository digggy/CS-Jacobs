/*
CH08-320142
Problem 4.6.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include<cmath>
#include"Vector.h"
#include<iostream>

using namespace std;

//Empty Constructor
Vector::Vector(){
    size=3;
    component= new double [3] {0,0,0};
}

//Constructor with parameters
Vector::Vector(int nSize,double*& nComponent){
    size=nSize;
    component=nComponent;    
}

//Copy Constructor
Vector::Vector(Vector& obj){
    size=obj.size;
    component=obj.component;
}

//Destructor
Vector::~Vector(){
    delete [] component;
}

//Setters of Vector
void Vector::setSize(int nSize){
    size=nSize;   
}

void Vector::setComponent(double*& nComponent){
    component=nComponent;    
}

//Getters of Vector
double* Vector::getComponent(){
    return component;
}

int Vector::getSize(){
    return size;
}

//Service Methods 
void Vector::print(){
    cout<<"[";
    for(int i=0;i<size;i++){
        if (i==size-1){
            cout<<component[i];
        }else{
            cout<<component[i]<<",";
        }
    }
    cout<<"]"<<endl;
}

// Method to find norm of the vector
double Vector::norm() const{
    double sum;
    
    for (int i=0;i<size;i++){
        sum+=component[i]*component[i];
    }

    return sqrt(sum);
}

//Addtion of vectors
Vector Vector::add(const Vector& obj) const{
    
    //setting a new component for new object
    double* nComponent= new double [size];

    for (int i=0;i<size;i++){    
        //adding the elements of the component
        nComponent[i]=component[i]+obj.component[i];
    }

    Vector sum (size,nComponent);
    return sum;
}

//Scalar Product of Vectors
double Vector::sProduct(Vector& obj)const{
    double product;

    for (int i=0;i<size;i++){
        product+=component[i]*obj.component[i];
    }

    return product;
}

//Difference of Vectors
Vector Vector::sub(const Vector& obj) const{
    //setting a new component for new object
    double* nComponent= new double [size];
    for (int i=0;i<size;i++){    
        nComponent[i]=component[i]-obj.component[i];
    }
    Vector difference (size,nComponent);
    return difference;
}