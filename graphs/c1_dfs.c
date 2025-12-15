#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5

int stack[MAX];
int top = -1;

struct vertex {
    char label; 
    bool visited;
};

struct vertex *last_vertices[MAX];

int adj_matrix[MAX][MAX];

int vertex_count = 0;

void push(int item) {
    stack[++top] = item;
}

int pop() {
    return stack[top--];
}

int peek() {
    return stack[top];
}

bool is_stack_empty() {
    return top == -1;
}

void add_vertex(char label) {
    struct vertex *vertex = (struct vertex*)malloc(sizeof(struct vertex));
    vertex->label = label;
    vertex->visited = false;
    last_vertices[vertex_count++] = vertex;
}

void add_edge(int start, int end) {
    adj_matrix[start][end] = 1;
    adj_matrix[end][start] = 1;
}

void display_vertex(int vertex_index) {
    printf("%c\t", last_vertices[vertex_index]->label);
}

int get_adj_unvisited_vertex(int vertex_index) {
    for (int i = 0; i < vertex_count; i++) {
        if (adj_matrix[vertex_index][i] == 1 && last_vertices[i]->visited == false) {
            return i;
        }
    }
    return -1;
}

void depth_first_search() {
    last_vertices[0]->visited = true;
    display_vertex(0);
    push(0);
    while (!is_stack_empty()) {
        int unvisited_vertex = get_adj_unvisited_vertex(peek());
        if (unvisited_vertex == -1)
            pop();
        else {
            last_vertices[unvisited_vertex]->visited = true;
            display_vertex(unvisited_vertex);
            push(unvisited_vertex);
        }
    }
}

int main() {
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            adj_matrix[i][j] = 0;

    add_vertex('S');
    add_vertex('A');
    add_vertex('B');
    add_vertex('C');
    add_vertex('D');
    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(0, 3);
    add_edge(1, 4);
    add_edge(2, 4);
    add_edge(3, 4);
    printf("\nDepth first search:\t");
    depth_first_search();
    printf("\n");
    return 0;
}
