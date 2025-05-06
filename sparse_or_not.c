#include <stdio.h>

int main() {
    int rows, cols;
    int i, j, count = 0;


    printf("Enter number of rows: ");
    scanf("%d", &rows);
    
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];


    printf("Enter matrix elements:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);


            if (matrix[i][j] == 0)
                count++;
        }
    }

    int total = rows * cols;

    if (count > total / 2)
        printf("The matrix is sparse.\n");
    else
        printf("The matrix is not sparse.\n");

    return 0;
}