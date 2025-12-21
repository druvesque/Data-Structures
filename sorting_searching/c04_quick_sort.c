#include<stdio.h>
#include<stdbool.h>
#define MAX 6

void quick_sort(int, int);
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
    quick_sort(0, MAX - 1);
    printf("\nOutput Array: ");
    display();
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int first, int last) {
    if (first < last) {
        int pivot = first, left = first, right = last;
        while (left < right) {
            while ((list[left] <= list[pivot]) && (left < last))
                left++;
            while (list[right] > list[pivot])
                right--;
            if (left < right) {
                swap(&list[left], &list[right]);
            }
        }
        swap(&list[pivot], &list[right]);
        quick_sort(first, right - 1);
        quick_sort(right + 1, last);
    }
}

