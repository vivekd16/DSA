#include <stdio.h>
#include <stdlib.h>
int main() {
    int *arr;
    int size=5;
    arr= (int *)malloc(size * sizeof(int)); //using typecast to change datatype from malloc to int and assing the size to arr using malloc 
    for(int i=0; i<size; i++){
        arr[i]=i +1;
    }
    arr = (int *)realloc(arr,(size+1)* sizeof(int)); //using this to change the memory of array using relloc 
    arr[size] =6;
    for (int i=0; i <size +1;i++) {
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}