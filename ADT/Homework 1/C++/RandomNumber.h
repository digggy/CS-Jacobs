/*
ADS
Problem 1.2
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <cstdlib>

#include "SelectionSort.h"

using namespace std;

class RandomNumber {

    public:
        static int max_range;
        //method to get the best case
        static double* bestCase(int n) {
            double* arr = new double[n];
            arr = averageCase(n);
            
            SelectionSort::sort(arr, n);

            return arr;
        }
        //method to get the average case
        static double* averageCase(int n) {
            double* arr = new double[n];
            for (int i=0; i<n; i++) {
                arr[i]= rand() % max_range + 1;
            }
            return arr;
        }
        //method to get the worst case
        static double* worstCase(int n) {
            double* arr = new double[n];
            arr = bestCase(n);

            for(int i=0; i<(n/2); i++) {
                double temp = arr[i];
                arr[i] = arr[n - i -1];
                arr[n - i - 1] = temp;
            }

            return arr;
        }

};
// max range of the numbers
int RandomNumber::max_range =  200;