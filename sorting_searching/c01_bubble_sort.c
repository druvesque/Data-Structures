#include<stdio.h>
#include<stdbool.h>
#define MAX 6

void bubble_sort(void);

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
    bubble_sort();
    printf("\nOutput Array: ");
    display();
}

void bubble_sort() {
    for (int i = 0; i < MAX - 1; i++) {
        for (int j = 0; j < MAX - i - 1; j++) {
            if (list[j] > list[j+1]) {
                int temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
            printf("i: %d, j: %d\t", i, j);
            display();
        }
        printf("\n");
    }
}
