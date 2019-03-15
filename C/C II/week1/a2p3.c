/*
JTSK-320112
Problem 2.3
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

void printMatrix(int** arr,int a,int b );

int main(int argc, char **argv)
{
    int n, m, p;
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &p);

    //Memory Allocation Matrix A 
    int ** matrixA ;
    matrixA = ( int **) malloc ( sizeof ( int *) * n) ;
    
    if ( matrixA == NULL )
    exit (1) ;
    
    for ( int row = 0; row < n; row ++) {
        matrixA [ row ] = ( int *) malloc ( sizeof ( int ) * m) ;
        if ( matrixA [ row ] == NULL )
        exit (1) ;
    }

    //Memory Allocation Matrix B
    int ** matrixB ;
    matrixB = ( int **) malloc ( sizeof ( int *) * m) ;
    
    if ( matrixB == NULL )
    exit (1) ;
    
    for ( int row = 0; row < m; row ++) {
        matrixB [ row ] = ( int *) malloc ( sizeof ( int ) * p) ;
        if ( matrixB [ row ] == NULL )
        exit (1) ;
        }

    //Memory Allocation Matrix C
    int ** matrixC;
    matrixC = ( int **) malloc ( sizeof ( int *) * n) ;
    if ( matrixC == NULL )
    exit (1) ;
    
    for ( int row = 0; row < n; row ++) {
        matrixC [ row ] = ( int *) malloc ( sizeof ( int ) * p) ;
        if ( matrixC [ row ] == NULL )
        exit (1) ;
    }

    //Getting Input
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d",&matrixA[i][j]);
        }   
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < p; j++){
            scanf("%d",&matrixB[i][j]);
        }   
    }

    //Calculation for the third matrix 
    for (int i = 0; i < n; i++){
        for (int k = 0; k < p; k++){
            for (int j=0;j<m;j++){
                matrixC[i][k]+=matrixA[i][j]*matrixB[j][k];
            }
        }   
    }
    //Printing Matrix A
    printf("Matrix A:\n");
    printMatrix(matrixA,n,m);
    //Printing Matrix B
    printf("Matrix B:\n");
    printMatrix(matrixB,m,p);
    //Printing Matrix C
    printf("The multiplication result AxB:\n");
    printMatrix(matrixC,n,p);

    //Freeing memory of the array 
    for (int i = 0; i < n ; i ++){
        free (matrixA[i]);}
    free (matrixA) ;
    
    for (int i = 0; i < m ; i ++){
        free (matrixB[i]);}
    free (matrixB) ;

    for (int i = 0; i < p ; i ++){
        free (matrixC[i]);}
    free (matrixC) ;
    
    
    return 0;
}

//Function to print matrixes
void printMatrix(int** arr,int a,int b ){
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            printf("%d ",arr[i][j]);
        }   
        printf("\n");
    }
}


