#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100
#define UNCOLORED 0
#define RED 1
#define BLUE 2

typedef struct {
    int data[MAX_NODES];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

bool isEmpty(Queue *q) {
    return q->front > q->rear;
}

void enqueue(Queue *q, int value) {
    if (q->rear < MAX_NODES - 1) {
        q->data[++q->rear] = value;
    }
}

int dequeue(Queue *q) {
    return q->data[q->front++];
}

bool isBipartite(int n, int graph[n][n]) {
    int color[n];
    for (int i = 0; i < n; i++) {
        color[i] = UNCOLORED;
    }

    Queue q;
    initQueue(&q);

    for (int start = 0; start < n; start++) {
        if (color[start] == UNCOLORED) {
            color[start] = RED;
            enqueue(&q, start);

            while (!isEmpty(&q)) {
                int node = dequeue(&q);

                for (int neighbor = 0; neighbor < n; neighbor++) {
                    if (graph[node][neighbor]) {
                        if (color[neighbor] == UNCOLORED) {
                            color[neighbor] = (color[node] == RED) ? BLUE : RED;
                            enqueue(&q, neighbor);
                        } else if (color[neighbor] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int n, e;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    int graph[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    if (isBipartite(n, graph)) {
        printf("Bipartite\n");
    } else {
        printf("Not Bipartite\n");
    }

    return 0;
}