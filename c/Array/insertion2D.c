#include <stdio.h>
void insert(int arr[][3],int row,int col,int value){
    arr[row][col]=value;
}
int main(){
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    insert(arr,1,1,99);
    for (int i=0;i<3; i++){
        for (int j=0;j<3;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}