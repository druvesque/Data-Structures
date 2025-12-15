#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;
int queue_count = 0;

struct vertex {
    char label;
    bool visited;
};

struct vertex *last_vertices[MAX];

int adj_matrix[MAX][MAX];

int vertex_count = 0;

void enqueue(int data) {
    queue[++rear] = data;
    queue_count++;
}

int dequeue() {
    queue_count--;
    return queue[++front];
}

bool is_queue_empty() {
    return queue_count == 0;
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

void breadth_first_search() {
    bool exist;
    enqueue(0);
    while(!is_queue_empty()) {
        int temp_vertex = dequeue();
        last_vertices[temp_vertex]->visited = true;
        display_vertex(temp_vertex);

        for (int i = 0; i < vertex_count; i++) {
            if (adj_matrix[temp_vertex][i] == 1 && last_vertices[i]->visited == false) {
                for (int j = front; j <= rear; j++) {
                    if (queue[j] == i)
                        exist = 1;
                }
                if (exist == 0)
                    enqueue(i);
            }
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
    breadth_first_search();
    printf("\n"); 
    return 0;
}
