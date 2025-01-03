#include <stdio.h>

int linearsearch(int arr[],int n,int value){
    for (int i= 0; i<n;i++){
        if (arr[i]==value){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[]={1,2,3,4,5};
    int n=5;
    int value=3;

    int index=linearsearch(arr,n,value);
    if (index!= -1){
        printf("%d",index);
    }
    else{
        printf("NO");
    }
    return 0;
}