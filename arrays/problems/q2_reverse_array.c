#include<stdio.h>

void swap(int*, int*);

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n/2 + 1; i++) {
        int *p1 = &arr[i];
        int *p2 = &arr[n - i - 1];
        swap(p1, p2);
    }
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a; 
    *a = *b;
    *b = temp;
}
