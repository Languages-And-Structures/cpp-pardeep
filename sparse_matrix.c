#include <stdio.h>

int convert_to_Sparse(int arr[][5],int rows,int cols,int sparse[][3]){
    int k=0;
    int i;
    for (i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j]!=0)
            {
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=arr[i][j];
                k++;
            }
            }
        }
        return k;
}

void convert_back_to_dense(int sparse[][3], int sparse_size, int rows, int cols) {
    int dense[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dense[i][j] = 0;
        }
    }
    for (int i = 0; i < sparse_size; i++) {
        int r = sparse[i][0];
        int c = sparse[i][1];
        int value = sparse[i][2];
        dense[r][c] = value;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", dense[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int arr[4][5]={
        {0, 0, 3, 0, 4},
        {0, 5, 0, 0, 0},
        {6, 0, 0, 7, 0},
        {0, 8, 0, 0, 9}
    };
    int rows = 4;
    int cols = 5;
    int sparse[rows*cols][3];
    int sparse_arr=convert_to_Sparse(arr, rows, cols,sparse);
    for (int i = 0; i < sparse_arr; i++)
    {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
    printf("\n");
    convert_back_to_dense(sparse, 7,rows, cols);
    printf("\n");
    
return 0;
}