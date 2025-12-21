#include<stdio.h>

int delete(int [], int, int);
void swap(int*, int*);

int main() {
    int arr[] = {1, 2 ,3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    size = delete(arr, size, 4);
    delete(arr, size, 7);
    return 0;
}

int delete(int arr[], int size, int pos) {
    if (size == 0) {
        printf("\nARRAY UNDERFLOW!");
        return 0;
    }
    if (pos > size) {
        printf("\nInvalid Index, Can't delete!");
        return size;
    }
    for (int i = pos - 1; i < size; i++) {
        int *p1 = &arr[i];
        int *p2 = &arr[i+1];
        swap(p1, p2);
    }
    size--;
    printf("\nAfter deletion:\t");
    for (int i = 0; i < size; i++)
        printf("%d\t", arr[i]);
    return size;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
