#include<stdio.h>

int insert(int[], int, int, int);
void swap(int*, int*);

int main() {
    int arr[] = {1, 2, 3, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    size = insert(arr, size, 4, 4);
    insert(arr, size, 8, 98);
    return 0;
}

int insert(int arr[], int size, int pos, int item) {
    if (pos > size + 1) {
        printf("\nInvalid index of insertion!");
        return size;
    }
    for (int i = size - 1; i >= pos-1; i--) {
        int *p1 = &arr[i];
        int *p2 = &arr[i+1];
        swap(p1, p2);
    }
    arr[pos-1] = item;
    size = size + 1;
    printf("\nAfter insertion:\t");
    for (int i = 0; i < size; i++)
        printf("%d\t", arr[i]);
    return size;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
