#include <stdio.h>
void delete(int arr[],int *n, int pos){
    for(int i=pos;i<*n-1;i++){
        arr[i]=arr[i+1]; // shifting the elemnt to the right 
    }
    (*n)--;
}
int main(){
    int arr[10]={1,2,3,4,5};
    int n=5;
    int pos=2;

    delete(arr,&n,pos);

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}