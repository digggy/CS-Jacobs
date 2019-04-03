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
}

//Constructor
Vector::Vector(int nSize,double*& nComponent){
    size=nSize;
    component=nComponent;    
}
//Destructor
Vector::~Vector(){
    delete [] component;
}

//Setters
void Vector::setSize(int nSize){
    size=nSize;   
}

void Vector::setComponent(double*& nComponent){
    component=nComponent;    
}

//Getters
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

double Vector::norm() const{
    double sum;
    for (int i=0;i<size;i++){
        sum+=component[i]*component[i];
    }
    return sqrt(sum);
}

Vector Vector::add(const Vector& obj) const{
    //setting a new component for new object
    double* nComponent= new double [size];
    for (int i=0;i<size;i++){    
        nComponent[i]=component[i]+obj.component[i];
    }
    Vector sum (size,nComponent);
    return sum;
}

double Vector::sProduct(Vector& obj)const{
    double product;
    for (int i=0;i<size;i++){
        product+=component[i]*obj.component[i];
    }

     cout<<product<<endl;
     cout<<obj.norm()<<endl;
     cout<<norm()<<endl;
     double a=norm();
     double b=obj.norm();
     cout<<a*b<<endl;

    return product/(obj.norm()*norm());
}