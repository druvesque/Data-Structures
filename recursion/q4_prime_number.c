#include<stdio.h>

void check_prime(int, int);

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num <= 1) {
        printf("\nNeither Prime nor Composite!");
        return 0;
    }
    check_prime(num, num/2);
    return 0;
}

void check_prime(int n, int d) {

    if (d == 2) {
        printf("\nIt's a prime number!");
        return;
    }
    if (n % d == 0) {
        printf("\nIt's a composite number!");
        return;
    }
    check_prime(n, d-1);
    
}
