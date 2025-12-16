#include<stdio.h>

void sum(int);
static int result;

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    sum(num);
    printf("Sum of first %d natural numbers: %d", num, result);
    return 0;
}

void sum(int n) {
    if (n == 0)
        return;
    sum(n-1);
    result = result + n;
}
