#include<stdio.h>
#define SIZE 10

struct stack {
    int stack[SIZE];
    int top;
} s;

void push();
void pop();
void display();

int main() {
    int choice, option = 1;
    s.top = -1;

    printf("STACK OPERATIONS\n");
    while(option) {
        printf("\n----------------\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("----------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Invalid Choice\n\n");
        }
        printf("\nDo you want to continue (press 0 or 1)?: ");
        scanf("%d", &option);
    }
}

void push() {
    int num;
    if (s.top == SIZE - 1) {
        printf("\nSTACK OVERFLOW");
        printf("\nStack is already full!");
    }
    else {
        printf("\nEnter the element to be pushed: ");
        scanf("%d", &num);
        s.top = s.top + 1;
        s.stack[s.top] = num;
    }
}

void pop() {
    int num;
    if (s.top == -1) {
        printf("\nSTACK UNDERFLOW");
        printf("\nStack is already empty!");
    }
    else {
        num = s.stack[s.top];
        printf("\nPopped element: %d", s.stack[s.top]);
        s.top = s.top - 1;
    }
}

void display() {
    printf("The stack is:\t");
    for (int i = s.top; i != -1; i--)
        printf("%d\t", s.stack[i]);
}

