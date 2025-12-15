#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *newnode(int item) {
    struct node *node = NULL;
    node = (struct node*)malloc(sizeof(struct node));
    if (node == NULL)
        printf("\nError creating the node!");
    node->data = item;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

void in_order(struct node *node) {
    if (node == NULL)
        return; 
    in_order(node->left);
    printf("%d\t", node->data);
    in_order(node->right);
}

void pre_order(struct node *node) {
    if (node == NULL)
        return;
    printf("%d\t", node->data);
    pre_order(node->left);
    pre_order(node->right);
}

void post_order(struct node *node) {
    if (node == NULL)
        return;
    post_order(node->left);
    post_order(node->right);
    printf("%d\t", node->data);
}

int main() {
    struct node *root;
    root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(10);
    printf("\nPre-order: ");
    pre_order(root);
    printf("\nIn-order: ");
    in_order(root);
    printf("\nPost-order: ");
    post_order(root);
    return 0;
}
