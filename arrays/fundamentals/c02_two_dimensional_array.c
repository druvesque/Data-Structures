#include<stdio.h>

int main() {
    int arr1[2][3], arr2[2][3], result[2][3];
    printf("\nEnter elements of first matrix\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("\nEnter elements of second matrix\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter element [%d][%d]: ", i , j);
            scanf("%d", &arr2[i][j]);
        }
    }
    for (int i = 0; i < 2; i++) 
        for (int j = 0; j < 3; j++)
            result[i][j] = arr1[i][j] + arr2[i][j];
    printf("\n\nAddition of 2 matrices:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            printf("%d\t", result[i][j]);
        printf("\n");
    }
    return 0;
}
