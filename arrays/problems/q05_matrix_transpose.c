#include<stdio.h>

void matrix_transpose(int rows, int cols, int[rows][cols], int[cols][rows]);

int main() {
    int rows, cols;
    printf("\nEnter no. of rows: ");
    scanf("%d", &rows);
    printf("\nEnter no. of columns: ");
    scanf("%d", &cols);
    printf("\n");
    
    int matrix[rows][cols];
    int transpose[cols][rows];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i , j);
            scanf("%d", &matrix[i][j]);
        }
    }
    matrix_transpose(rows, cols, matrix, transpose);
    printf("\n\nBefore Transpose: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) 
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }   
    printf("\n\nAfter Transpose: \n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++)
            printf("%d\t", transpose[i][j]);
        printf("\n");
    }
    return 0;
}

void matrix_transpose(int rows, int cols, int matrix[rows][cols], int transpose[cols][rows]) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
            printf("\ni: %d, j: %d, matrix: %d, transpose: %d", i, j, matrix[i][j], transpose[j][i]);
        }
}
