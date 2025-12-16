#include<stdio.h>

int main() {
    int sum = 0; 
    float avg;
    int arr[10];
    for (int i = 0; i < 10; i++) {
        printf("\nEnter element %d: ", i+1);
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
    }
    avg = sum / 10;
    for (int i = 0; i < 10; i++)
        printf("\nElement at %d: %d", i+1, arr[i]);
    printf("\n\nAverage of the elements in the array: %f", avg);
    return 0;
}
