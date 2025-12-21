#include<stdio.h>
#include<stdbool.h>
#define MAX 6

void merge_sort(int, int);
void merge(int, int, int);

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
    merge_sort(0, MAX - 1);
    printf("\nOutput Array: ");
    display();
}

void merge_sort(int first, int last) {
    int mid;
    if (first < last) {
        mid = (first + last) / 2;
        merge_sort(first, mid);
        merge_sort(mid + 1, last);
        merge(first, mid, last);
    }
}

void merge(int first, int mid, int last) {
    int i, j, k;
    int arr[MAX];
    i = first;
    j = mid + 1;
    k = first;

    while (i <= mid && j <= last) {
        if (list[i] <= list[j]) {
            arr[k] = list[i];
            i++;
        }
        else {
            arr[k] = list[j];
            j++;
        }
        k++;
    }

    if (i > mid) {
        while (j <= last) {
            arr[k] = list[j];
            j++;
            k++;
        }
    }

    else {
        while (i <= mid) {
            arr[k] = list[i];
            i++;
            k++;
        }
    }

    for (k = first; k <= last; k++)
        list[k] = arr[k];
}


