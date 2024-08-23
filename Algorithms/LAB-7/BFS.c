#include <stdio.h>
#include <stdlib.h>
#define V 6

struct Queue
{
    int items[V];
    int front;
    int rear;
};

struct Graph
{
    int adjMatrix[V][V];
};

struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(struct Queue *queue)
{
    if (queue->rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(struct Queue *queue, int value)
{
    if (queue->rear == V - 1)
        printf("\nQueue is Full!!");
    else
    {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

int dequeue(struct Queue *queue)
{
    int item;
    if (isEmpty(queue))
    {
        printf("\nQueue is Empty!!");
        item = -1;
    }
    else
    {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear)
        {
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

void initializeGraph(struct Graph *graph)
{
    int i, j;
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(struct Graph *graph, int u, int v)
{
    graph->adjMatrix[u][v] = 1;
    graph->adjMatrix[v][u] = 1;
}

void BFS(struct Graph *graph, int startVertex)
{
    // Initialize arrays to store color, predecessors, and distances
    int color[V]; // WHITE = 0, GREY = 1, BLACK = 2
    int prev[V];
    int d[V];

    struct Queue *queue = createQueue();

    int i, u, v;

    for (i = 0; i < V; i++)
    {
        color[i] = 0;       // WHITE
        prev[i] = -1;       // NIL
        d[i] = __INT_MAX__; // Infinity
    }

    // Set start vertex properties
    color[startVertex] = 1; // GREY
    d[startVertex] = 0;
    prev[startVertex] = -1; // NIL

    // Enqueue start vertex
    enqueue(queue, startVertex);

    // Perform BFS
    while (!isEmpty(queue))
    {
        u = dequeue(queue);
        printf("%d ", u); // Print the current vertex

        // Traverse all adjacent vertices of u
        for (v = 0; v < V; v++)
        {
            if (graph->adjMatrix[u][v] == 1)
            { // If there is an edge between u and v
                if (color[v] == 0)
                {                      // If v is WHITE
                    color[v] = 1;      // Set v as GREY
                    d[v] = d[u] + 1;   // Update distance to v
                    prev[v] = u;       // Set u as predecessor of v
                    enqueue(queue, v); // Enqueue v
                }
            }
        }
        color[u] = 2; // Set u as BLACK
    }
}

int main()
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    initializeGraph(graph);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    printf("Breadth First Traversal (starting from vertex 0):\n");
    BFS(graph, 2); // Start BFS from vertex 0

    return 0;
}