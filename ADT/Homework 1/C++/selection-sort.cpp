/*
ADS
Problem 1.2
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <fstream>

using namespace std;

#define sizeStart 0
#define sizeEnd 38000
#define sizeStep 800
#define averageTime 5 


#include "RandomNumber.h"
#include "SelectionSort.h"

void printArray(double* arr, int n);

int main(int argc,char** argv){
    
    srand(static_cast<unsigned int>(time(0)));

    ofstream myfile;
    myfile.open ("data.txt");

    for(int n=sizeStart; n<sizeEnd; n+=sizeStep) {
     
        double * arr = new double[n];
        double worstCaseTime, bestCaseTime, averageCaseTime;
        double timeCounter;


        // for every case, take data multiple times    
        
        // For Best Case 
        timeCounter = 0;
        for(int i=0; i<averageTime; i++) {
            arr = RandomNumber::bestCase(n);
            auto startTime = chrono::system_clock::now();
            SelectionSort::sort(arr, n);
            auto endTime = chrono::system_clock::now();

            chrono::duration<double> diff = endTime - startTime;
            timeCounter += diff.count();
        }
        bestCaseTime = timeCounter / averageTime ;
        cout << bestCaseTime << endl;
        

        // For Average Case
        timeCounter = 0;
        for(int i=0; i<averageTime; i++) {
            arr = RandomNumber::averageCase(n);
            auto startTime = chrono::system_clock::now();
            SelectionSort::sort(arr, n);
            auto endTime = chrono::system_clock::now();

            chrono::duration<double> diff = endTime - startTime;
            timeCounter += diff.count();
        }
        averageCaseTime = timeCounter / averageTime;
        cout << averageCaseTime << endl;
        //For Worst Case
        timeCounter = 0;
        for(int i=0; i<averageTime; i++) {
            arr = RandomNumber::worstCase(n);
            auto startTime = chrono::system_clock::now();
            SelectionSort::sort(arr, n);
            auto endTime = chrono::system_clock::now();

            chrono::duration<double> diff = endTime - startTime;
            timeCounter += diff.count();
        }
        worstCaseTime = timeCounter / averageTime;
        //cout << worstCaseTime << endl;

        myfile << n << " " << bestCaseTime << " " << averageCaseTime << " " << worstCaseTime << " " << endl;
        
    }

    myfile.close();

    return 0;
}

//Function to print the elements of an array
/*
 void printArray(double* arr, int n) {
     cout<<"[";
     for(int i=0; i<n; i++) {
         cout << arr[i] <<", ";
     }
     cout<<"]"<<endl;
 }
*/

