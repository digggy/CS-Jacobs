/*
CH08-320142
Problem 3.1.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include<iostream>
#include "Box.h"

using namespace std;

int main(int arc,char** argv){
    int number;
    double height;
    double width;
    double depth;
    double sum=0;

    //asking the number of boxes 
    cout<<"Enter the number of Boxes "<<endl;
    cin>>number;
    Box* box = new Box[number];
    
    //setting the values of the objects in the array
    for (int i =0;i<number;i++){
        cout<< "============================="<<endl;
        cout<< "Enter the Information of Box "<<(i+1)<<endl;
        cout<< "============================="<<endl;

        cout<<"Height"<<endl;
        cin>>height;
        box[i].setHeight(height);

        cout<<"Width"<<endl;
        cin>>width;
        box[i].setWidth(width);

        cout<<"Depth"<<endl;
        cin>>depth;
        box[i].setDepth(depth);
 
    } 

    //printing out the volume
    cout<< "========= The Volume =========="<<endl;

    for (int i =0;i<number;i++){
        cout<<"Volume of BOX ("<< (i+1) <<") :"<<box[i].volume()<<endl;
        sum+=box[i].volume();
    }      
    cout<< "=========+++++++++++++=========="<<endl;
    cout<<"The sum of volumes :"<<sum<<endl;
    
    //freeing memory
    delete [] box;
    return 0;
}
