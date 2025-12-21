#include<stdio.h>

void matrix_multiplication(int r1, int c1, int matrix1[r1][c1], int r2, int c2, int matrix2[r2][c2], int result[r1][c2]);

int main() {
    int r1, c1, r2, c2;
    printf("Enter no. of rows for 1st matrix: ");
    scanf("%d", &r1);
    printf("Enter no. of columns for 1st matrix: ");
    scanf("%d", &c1);
    
    int matrix1[r1][c1];
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }

    printf("Enter no. of rows for 2nd matrix: ");
    scanf("%d", &r2);
    printf("Enter no. of columns for 2nd matrix: ");
    scanf("%d", &c2);
    
    int matrix2[r2][c2];
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }

    int result[r1][c2];
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            result[i][j] = 0;

    if (c2 != r1) {
        printf("\nThese matrices cannot be multiplied!");
        return 0;
    }
    matrix_multiplication(r1, c1, matrix1, r2, c2, matrix2, result);
    printf("\n\nResult:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            printf("%d\t", result[i][j]);
        printf("\n");
    }
    return 0;
}

void matrix_multiplication(int r1, int c1, int matrix1[r1][c1], int r2, int c2, int matrix2[r2][c2], int result[r1][c2]) {
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++) 
                result[i][j] += matrix1[i][k] * matrix2[k][j];  
} 
