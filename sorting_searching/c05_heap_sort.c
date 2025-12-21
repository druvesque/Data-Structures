#include<stdio.h>
#include<stdbool.h>
#define MAX 6

void heap_sort(int);
void max_heapify(int, int);
void swap(int*, int*);

int list[MAX] = {15, 4, 23, 12, 56, 2};

void display() {
    printf("[");
    for (int i = 0; i < MAX; i++) {
        printf(" %d ", list[i]);
    }
    printf("]\n");
}

void main() {
    printf("Input Array: ");
    display();
    printf("\n");
    heap_sort(MAX);
    printf("\nOutput Array: ");
    display();
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    while (left < n && list[left] > list[largest])
        largest = left;

    while (right < n && list[right] > list[largest])
        largest = right;

    if (largest != i) {
        swap(&list[largest], &list[i]);
        max_heapify(n, largest);
    }
}

void heap_sort(int n) {
    for (int i = (n/2 - 1); i >= 0; i--)
        max_heapify(n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(&list[0], &list[i]);
        max_heapify(i, 0);
    }
}


