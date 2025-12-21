#include<stdio.h>
#include<stdbool.h>
#define MAX 6

void linear_search(int);

int list[MAX] = {15, 4, 23, 12, 56, 2};

void main() {
    int item;
    printf("Enter the element you want to search: ");
    scanf("%d", &item);
    linear_search(item);
}

void linear_search(int item) {
    for (int i = 0; i < MAX; i++) {
        if (list[i] == item) {
            printf("\nElement Found at index: %d", i);
            return;
        }
    }
    printf("Element not found");
}
