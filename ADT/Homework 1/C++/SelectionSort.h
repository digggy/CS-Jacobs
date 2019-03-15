/*
ADS
Problem 1.2
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#ifndef _SelectionSort_H_
#define _SelectionSort_H_

class SelectionSort{

    public:
        static void sort(double* arr, int n) {
            int i, j, min_index,tmp; 
            for (i = 0; i < n-1; i++) 
            { 
                // Finding  the minimum element in unsorted array 
                min_index = i; 
                for (j = i+1; j < n; j++) {
                    if (arr[j] < arr[min_index]) 
                        min_index = j; 
                }
                        
                // Swap the found minimum element with the element in index i of the array  
                if(min_index != i) {
                    tmp=arr[min_index];
                    arr[min_index]=arr[i];
                    arr[i]=tmp;
                }
                
            }
        }

};

#endif
