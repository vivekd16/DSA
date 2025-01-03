#include <stdio.h>
void delete(int arr[][3],int row,int col){
    arr[row][col]=0;
}
int main(){
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    delete(arr,1,1);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}