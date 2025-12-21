#include<stdio.h>
#include<stdbool.h>
#define MAX 6

void binary_search(int);
void bubble_sort(void);

int list[MAX] = {15, 4, 23, 12, 56, 2};

void main() {
    int item;
    printf("Enter the element you want to search: ");
    scanf("%d", &item);
    bubble_sort();
    binary_search(item);
}

void bubble_sort() {
    for (int i = 0; i < MAX - 1; i++) {
        for (int j = 0; j < MAX - i - 1; j++) {
            if (list[j] > list[j+1]) {
                int temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}

void binary_search(int item) {
    int first, last, mid;
    first = 0, last = MAX - 1; 
    mid = (first + last) / 2; 

    while (first <= last) {

        if (list[mid] < item)
            first = mid + 1;

        else if (list[mid] == item) {
            printf("\nElement Found at index: %d", mid);
            return;
        }

        else
            last = mid - 1;
        mid = (first + last) / 2;
    }
    printf("\nElement Not Found");
}

