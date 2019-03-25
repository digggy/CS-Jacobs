#include <stdio.h>
#include <string.h>

void print_char_arr(char a[], int n) {
    int i;
    for(i=0; i<n; i++)
        printf("%c ", a[i]);
    printf("\n");
}

void print_int_arr(int a[], int n) {
    int i;
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(){
    char c_arr[20];
    // ASCII code of 'A'
    char val1 = 65;
    // first 10 bytes will be filled with 65 (i.e., 'A')
    printf("Memset with char on char array\n");
    memset(c_arr, val1, 10);
    print_char_arr(c_arr, 20);
    // binary rep. of 2886 is 00001011 01000110
    // last byte is 01000110 which is decimally 70
    // 70 is the ASCII code of 'F'
    int val2 = 2886;
    printf("Memset with int on char array\n");
    memset(c_arr, val2, 20);
    print_char_arr(c_arr, 20);
    int int_arr[10];
    // first 10 bytes will be filled with 70 
    // later printed as ints
    printf("Memset with char on int array\n");
    memset(int_arr, val2, 10);
    print_int_arr(int_arr, 20);
    return 0;
}