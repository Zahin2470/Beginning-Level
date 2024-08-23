#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

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

void bfs(int n, int graph[n][n], int source) {
    bool visited[n];
    int distance[n];
    int parent[n];

    for (int i = 0; i < n; i++) {
        visited[i] = false;
        distance[i] = -1;
        parent[i] = -1;
    }

    Queue q;
    initQueue(&q);

    visited[source] = true;
    distance[source] = 0;
    enqueue(&q, source);

    while (!isEmpty(&q)) {
        int current = dequeue(&q);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = true;
                distance[i] = distance[current] + 1;
                parent[i] = current;
                enqueue(&q, i);
            }
        }
    }

    // Print paths and costs
    for (int i = 0; i < n; i++) {
        if (i != source) {
            printf("Path %d to %d: ", source, i);
            int path[MAX_NODES];
            int path_len = 0;

            for (int at = i; at != -1; at = parent[at]) {
                path[path_len++] = at;
            }

            for (int j = path_len - 1; j >= 0; j--) {
                printf("%d", path[j]);
                if (j > 0) printf("->");
            }

            printf(" Cost: %d\n", distance[i]);
        }
    }
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

    int source;
    printf("Enter source node: ");
    scanf("%d", &source);

    bfs(n, graph, source);

    return 0;
}