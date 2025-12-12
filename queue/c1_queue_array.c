#include<stdio.h>
#define SIZE 10

struct queue {
    int queue[SIZE];
    int front;
    int rear;
} q;

void enqueue();
void dequeue();
void display();

int main() {
    int choice, option = 1;
    q.front = -1;
    q.rear = -1;

    printf("\nQUEUE OPERATIONS\n");
    while (option) {
        printf("----------------\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("----------------\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("\nScanf failed!\n");
            while(getchar() != '\n');
            continue;
        }

        switch(choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Choice\n\n");
        }
        printf("\nDo you want to continue (press 0 or 1)? :  ");
        scanf("%d", &option);
    } 
    return 0;
}

void enqueue() {
    int item;
    if (q.rear == SIZE - 1)
        printf("QUEUE OVERFLOW");
    else {
        if (q.front == -1 && q.rear == -1)
            q.front = 0;
        printf("\nEnter the element: ");
        scanf("%d", &item);
        q.queue[++(q.rear)] = item;
    }
}

void dequeue() {
    if (q.front == -1 && q.rear == -1) 
        printf("QUEUE UNDERFLOW");
    else if (q.front == q.rear) {
        printf("\nDeleted Element: %d", q.queue[q.front]);
        q.front = q.rear = -1;
    }
    else {
        printf("\nDeleted Element: %d", q.queue[q.front]);
        (q.front)++;
    } 
}

int is_full() {
    return (q.rear == SIZE - 1) ? 1 : 0;
}

int is_empty() {
    return (q.front == -1 && q.rear == -1) ? 1 : 0;
}

void display() {
    if (is_empty()) {
        printf("\nQueue is empty!");
        return;
    }
    printf("The Queue is:\t");
    for (int i = q.front; i <= q.rear; i++) 
        printf("%d\t", q.queue[i]); 
    printf("\n");
}
