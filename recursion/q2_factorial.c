#include<stdio.h>

void factorial(int);
static int result = 1;

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    factorial(num);
    printf("Factorial: %d", result);
    return 0;
}

void factorial(int n) {
    if (n == 1)
        return;
    factorial(n-1);
    result = result * n;
}
