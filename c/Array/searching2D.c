#include <stdio.h>
int linearsearch(int arr[][3],int rows,int col,int value){
    for (int i =0 ; i<rows; i++){
        for(int j=0;j<col;j++){
            if (arr[i][j] ==value){
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int value=5;
    if(linearsearch(arr,3,3,value)){
        printf("YES");
    }
    else {
        printf("NO");
    }
}