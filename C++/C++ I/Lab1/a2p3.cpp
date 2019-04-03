/*
CH08-320142
Problem 2.3.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include<iostream>
using namespace std;

void add_min(int n,int*& arr);
void deallocate(int*& arr);

int main (int argc,char** argv){
    int n;
    cout<<"Input the size of array"<<endl;
    cin>>n;
    cout<<"Input the elements"<<endl;
    int *array=new int[n];

    //Asking the user the elements of array
    for (int i=0;i<n;i++){
        cin>>array[i];
    }
    add_min(n,array);
    for (int i=0;i<n;i++){
         cout<<array[i]<<endl;
    }
    
    //deallocating memory of array
    deallocate(array);
    return 0;      
}

/*function to find the minimum and add the minimum value
to every element of the array*/

void add_min(int n,int*& arr){
    int min=arr[0];
    for (int i=0;i<n;i++){
        (arr[i]<min)?min=arr[i]:min=min;
    }
    cout<<"The new array is : "<<endl;
    for (int i=0;i<n;i++){
        arr[i]+=min;
    }
}

//funtion to deallocate memory of an array
void deallocate(int*& arr){
    delete [] arr;
}
