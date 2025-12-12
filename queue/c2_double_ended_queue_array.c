#include<stdio.h>
#define SIZE 10

struct queue {
    int queue[SIZE];
    int front;
    int rear;
} q;

int is_full() {
    return (q.rear == (SIZE - 1)) ? 1 : 0;
}

int is_empty() {
    return (q.front == -1 && q.rear == -1) ? 1 : 0;
}

void insert_rear(int item) {
    if (is_full()) {
        printf("QUEUE OVERFLOW!\n");
        return;
    }
    if (is_empty())
        q.front = 0;
    q.queue[++(q.rear)] = item;
}

void insert_front(int item) {
    if (is_full()) {
        printf("QUEUE OVERFLOW!\n");
        return;
    }
    if (is_empty()) 
        q.rear = 0;
    q.queue[--(q.front)] = item;
} 

void delete_front() {
    if (is_empty()) {
        printf("QUEUE UNDERFLOW");
        return;
    }
    else if (q.rear == q.front) {
        printf("\nDeleted Element: %d", q.queue[q.front]);
        q.front = q.rear = -1;
    }
    else
        printf("\nDeleted Element: %d", q.queue[(q.front)++]);
}

void delete_rear() {
    if (is_empty()) {
        printf("\nQUEUE UNDERFLOW");
        return;
    }
    else if (q.front == q.rear) {
        printf("\nDeleted Element: %d", q.queue[q.rear]);
        q.front = q.rear = -1;
    }
    else
        printf("\nDeleted Element: %d", q.queue[(q.rear)--]);
}

void display() {
    if (is_empty()) {
        printf("\nQueue is Empty!");
        return;
    }
    printf("The Queue is:\t");
    for (int i = q.front; i <= q.rear; i++)
        printf("%d\t", q.queue[i]);
}

int main() {
    q.front = -1;
    q.rear = -1;
    insert_rear(10);
    display();
    insert_rear(20);
    display();
    insert_rear(40);
    display();
    delete_front();
    display();
    delete_rear();
    display();
    insert_front(50);
    display();
    return 0;
}
