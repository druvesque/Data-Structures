#include<stdio.h>

int matrix_addition(int arr1[][], int arr2[][]); 

int main() {
    int arr1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int arr2[2][3] = {{1, 2, 3}, {4, 5, 6}};

    int r1 = sizeof(arr1);
    int r2 = sizeof(arr2);

    int result = matrix_addition(arr1, arr2);

    if (result == -1) {
        printf("\nOperation Abandoned!");
        return 0;
    }

    printf("\nThe Matrix is: \n");
    
    for (int i = 0; i < sizeof(result); i++) {
        for (int j = 0; j < sizeof(result[0]); j++)
            printf("%d\t", result[i][j]);
        printf("\n");
    }
    return 0;
}

int matrix_addition(int arr1[][], int arr2[][]) {

    int r1 = sizeof(arr1);
    int r2 = sizeof(arr2);
    int c1 = sizeof(arr1[0]);
    int c2 = sizeof(arr2[0]);

    if ((r1 != r2) && (c1 != c2)) {
        printf("Matrix Addition not possible, the order of the matrices is different!");
        return -1;
    }

    int result[r1][c1];

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++) 
            result[i][j] = arr1[i][j] + arr2[i][j];
    
    return result;
}
