#include<stdio.h>
#include<stdbool.h>
#define MAX 6

void insertion_sort(void);

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
    insertion_sort();
    printf("\nOutput Array: ");
    display();
}

void insertion_sort() {
    for (int i = 1; i <= MAX - 1; i++) {
        int j = i - 1;

        while (j >= 0 && (list[j] > list[j+1])) {
            int temp = list[j];
            list[j] = list[j+1];
            list[j+1] = temp;
            j--;
        }
    }
}
