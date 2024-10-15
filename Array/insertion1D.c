#include <stdio.h>
 void insert(int arr[],int *n, int pos ,int value){     //using pointer because if we pass direct value of n then if any changes occur in this function then it will only get change in this function not in memory thats why we are using pointer

    for (int i =*n;i>pos;i--){
        arr[i]=arr[i-1]; //shifting element ot the right 
    }
    arr[pos]=value;
    (*n)++;
 }
 int main(){
    int arr[10]={1,2,3,4,5};
    int n=5;
    int pos =2;
    int value=99;
    insert(arr,&n,pos,value); //for inserting the number in array we have to first shift the elements in array and then we have to insert it
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
 }