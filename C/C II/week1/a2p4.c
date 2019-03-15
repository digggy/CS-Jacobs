/*
JTSK-320112
Problem 2.4
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

void printMatrix(int*** arr,int r,int c,int d );
void getMatrix(int*** arr,int r,int c,int d );

int main(int argc, char **argv)
{
    int r, c, d;
    //Get row,col and depth
    scanf("%d", &r);
    scanf("%d", &c);
    scanf("%d", &d);

    //Memory Allocation for the 3D
    int *** matrix ;
    matrix = ( int ***) malloc ( sizeof ( int **) * r) ;
    if ( matrix == NULL )
    exit (1) ;
    
    for ( int row = 0; row < r; row ++) {
        matrix[row] = ( int **) malloc ( sizeof ( int ) * c) ;
        if ( matrix[row] == NULL )
        exit (1) ;
        for (int col=0;col<c;col++){
            matrix[row][col]=(int*) malloc(sizeof(int)*d);
            if ( matrix[row][col] == NULL )
            exit (1) ;
        }
    }
    
    //Get Input from the user
    getMatrix(matrix,r,c,d );
    
    //Print Layers
    printMatrix(matrix,r,c,d );

    return 0;
}

//Function to print 3d layers
void printMatrix(int*** arr,int r,int c,int d ){
    for(int k=0;k<d;k++){
        printf("Section %d:\n",k+1);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                printf("%d ",arr[i][j][k]);
            }
            printf("\n");
        }
    }
}

//Function to get matrixe element
void getMatrix(int*** arr,int r,int c,int d ){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            for(int k=0;k<d;k++){
                scanf("%d",&arr[i][j][k]);
            }
        }
    }
 }


