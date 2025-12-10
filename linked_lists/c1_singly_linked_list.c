#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* create_list() {
    int choice = 1;
    struct node *head, *newnode, *temp;
    head = NULL;

    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter Data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
            head = temp = newnode;
        else {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Enter More? Press 1 Otherwise 0: ");
        scanf("%d", &choice);
    }
    return head;
}

struct node* insert_front(struct node *head) {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data you want to insert at the front: ");
    scanf("%d", &temp->data);
    temp->next = head;
    return temp;
}

int length_ll(struct node *head) {
    struct node *temp;
    int length = 0;
    temp = head;
    printf("The Linked List is: ");
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
        length++;
    }
    printf("\nTraversed, the length is: %d", length);
    return length;
}

struct node* insert_rear(struct node *head) {
    struct node *t1, *t2;
    t1 = (struct node*)malloc(sizeof(struct node));
    printf("Enter data you want to insert at rear: ");
    scanf("%d", &t1->data);
    t1->next=  NULL;
    t2 = head;
    while (t2->next != NULL)
        t2 = t2->next;
    t2->next = t1;
    return head;
}

struct node* insert_pos(struct node *head, int count) {
    int pos, i = 1;
    struct node *t1, *t2;
    t1 = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the position: ");
    scanf("%d", &pos);
    if (pos > count + 1)
        printf("Invalid Position\n");
    else if (pos > count) 
        head = insert_rear(head);
    else if (pos == 1)
        head = insert_front(head);
    else {
        t2 = head;
        while (i < pos - 1) {
            t2 = t2->next;
            i++;
        }

        printf("\nEnter data you want to enter at the specified position: ");
        scanf("%d", &t1->data);
        t1->next = t2->next;
        t2->next = t1;
    }
    return head;
}

struct node* delete_front(struct node *head) {
    struct node *temp;
    if (head == NULL)
        printf("\nList is empty!");
    else {
        temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

struct node* delete_rear(struct node *head) {
    struct node *temp, *prev;
    if (head == NULL) 
        printf("\nList is empty!");
    else {
        temp = head;
        while(temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
    }
    if (temp == head)
        head = NULL;
    else
        prev->next = NULL;

    free(temp);
    return head;
}

struct node* delete_pos(struct node *head, int count) {
    int pos, i = 1;
    struct node *current, *temp;
    printf("Enter the position: ");
    scanf("%d", &pos);
    if (pos > count || pos == 0)
        printf("\nInvalid Position");
    else if (pos == 1)
        head = delete_front(head);
    else {
        temp = head;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        current = temp->next;
        temp->next = current->next;
        printf("\nDeleted element: %d", current->data);
    }
    free(current);
    return head;
}

int main() {
    struct node *head = NULL;
    int total_elements;
    head = create_list();
    head = insert_front(head);
    head = insert_rear(head);
    total_elements = length_ll(head);
    head = insert_pos(head, total_elements);
    head = delete_front(head);
    head = delete_rear(head);
    total_elements = length_ll(head);
    head = delete_pos(head, total_elements);
    return 0;
}
