#include<stdio.h>
#include<stdbool.h>
#define MAX 6

void selection_sort(void);

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
    selection_sort();
    printf("\nOutput Array: ");
    display();
}

void selection_sort() {
    for (int i = 0; i < MAX; i++) {
        for (int j = i + 1; j < MAX; j++) {
            if (list[i] > list[j]) {
                int temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
            printf("i: %d, j: %d\t", i, j);
            display();
        }
        printf("\n");
    }
}

