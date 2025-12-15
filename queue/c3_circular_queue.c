#include<stdio.h>
#define SIZE 10

struct queue {
    int queue[10];
    int front;
    int rear;
} q;

int count = 0;

int is_full(int count) {
    return (count == SIZE);
}

int is_empty(int count) {
    return (count == 0);
}

void enqueue(int item) {
    if (is_empty(count)) {
        q.front = q.rear = 0;
        q.queue[q.rear] = item;
        count++;
    }
    else if (is_full(count)) {
        printf("QUEUE OVERFLOW\n");
    }
    else {
        q.rear = (q.rear + 1) % SIZE;
        q.queue[q.rear] = item;
        count++;
    }
}

void dequeue() {
    if (is_empty(count)) {
        printf("QUEUE UNDERFLOW\n");
    }
    else if (q.front == q.rear) {
        printf("\nDeleted Element: %d", q.queue[q.front]);
        q.front = q.rear = -1;
        count = 0;
    }
    else {
        printf("\nDeleted Element: %d", q.queue[q.front]);
        q.front = (q.front + 1) % SIZE;
        count--;
    }
}

void display() {
    int i = q.front;

    if (is_empty(count)) {
        printf("\nQueue is empty!");
        return;
    }

    printf("\nQueue is:\t");
    for (int j = 0; j < count; j++) {
        printf("%d\t", q.queue[i]);
        i = (i + 1) % SIZE;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    dequeue();
    display();
    dequeue();
    display();
    return 0;
}
