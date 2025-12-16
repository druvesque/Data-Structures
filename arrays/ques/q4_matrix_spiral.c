#include<stdio.h>

void spiral_printing(int rows, int cols, int arr[rows][cols]);

int main() {
    return 0;
}

void spiral_printing(int rows, int cols, int arr[rows][cols]) {

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++)
            printf("%d\t", arr[top][j]);
        top++;

        for (int i = top; i <= bottom; i++) 
            printf("%d\t", arr[i][right]);
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                printf("%d\t", arr[bottom][j]);
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d\t", arr[i][left]);
            left++;
        }
    }
}
