#include <stdio.h>
void bubblesort(int arr[],int n){
    for(int i =0; i<n-1; i++){
        for (int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                int temp =arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            //for(int k=0;k<n;k++){
            //    printf("%d ",arr[k]);    //for better understanding use this 
            //}
            //printf("\n");
        }
        //printf("E ");
    }
}
int main(){
    int arr[]={5,2,9,1,5,6};
    int n =sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}