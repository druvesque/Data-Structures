#include<stdio.h>

void print(int);

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    print(num);
}

void print(int n) {
    if (n == 0)
        return;
    print(n-1);
    printf("%d\t", n);
}


