#include<stdio.h>

void product(int, int);
static int result = 0;

int main() {
    int num1, num2;
    printf("Enter number1: ");
    scanf("%d", &num1);
    printf("Enter number2: ");
    scanf("%d", &num2);
    product(num1, num2);
    printf("Product of %d & %d: %d", num1, num2, result);
    return 0;
}

void product(int a, int b) {
    if (b == 0)
        return;
    product(a, b-1);
    result = result + a;
}
