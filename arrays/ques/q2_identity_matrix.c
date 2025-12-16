#include<stdio.h>

int create_identity_matrix(int);
int is_identity_matrix(int, int, int[][]);

int main() {

    int size;
    printf("Enter size of the identity matrix you want to create: ");
    scanf("%d", &size);
    
    int matrix[size][size] = create_identity_matrix(size);

    printf("\nCheck: %d", is_identity_matrix(size, size, matrix[size][size]));
    return 0;
}

int is_identity_matrix(int rows, int cols, int arr[rows][cols]) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (((i != j) && (arr[i][j] != 0)) && ((i == j) && (arr[i][j] != 1)))
                return 0;
        }
    }

    return 1;
}

int create_identity_matrix(int size) {

    int identity_matrix[size][size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j)
                identity_matrix[i][j] = 1;
            else
                identity_matrix[i][j] = 0;
        }
    }

    return identity_matrix;
}


