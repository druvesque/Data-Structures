#include<stdio.h>

void fibonacci(int);
static int a = 0;
static int b = 1;

int main() {
    int num;
    printf("Enter number of terms: ");
    scanf("%d", &num);
    fibonacci(num);
    return 0;
}

void fibonacci(int n) {
    if (n == 1) {
        printf("Fibonacci Series: %d", a);
        return;
    }
    if (n == 2) {
        printf("Fibonacci Series: %d\t%d", a, b);
        return;
    }
    fibonacci(n-1);
    int next_term = a + b;
    a = b;
    b = next_term;
    printf("\t%d", b);

}
