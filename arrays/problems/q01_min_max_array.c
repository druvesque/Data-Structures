#include<stdio.h>
#include<limits.h>

void min_max(int[], int);

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    min_max(arr, size);
    return 0;
}

void min_max(int arr[], int size) {
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    printf("\nMin: %d, Max: %d", min, max);
}
