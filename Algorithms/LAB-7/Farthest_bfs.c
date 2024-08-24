#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Function to perform BFS and find the farthest node
int farthestNodeBFS(int start, int n, int graph[MAX_NODES][MAX_NODES]) {
    // Initialize an array to keep track of visited nodes
    int visited[MAX_NODES] = {0};
    // Create a queue for BFS
    int queue[MAX_NODES];
    int front = 0, rear = -1;
    // Enqueue the starting node
    queue[++rear] = start;
    visited[start] = 1; // Mark the starting node as visited

    int farthestNode = start;
    // Perform BFS
    while (front <= rear) {
        int size = rear - front + 1;
        for (int i = 0; i < size; ++i) {
            int u = queue[front++]; // Dequeue a node
            // Traverse all the adjacent nodes of dequeued node 'u'
            for (int v = 1; v <= n; ++v) {
                if (graph[u][v] && !visited[v]) { // If there is an edge and the adjacent node is not visited
                    visited[v] = 1; // Mark it as visited
                    queue[++rear] = v; // Enqueue it
                    farthestNode = v; // Update the farthest node
                }
            }
        }
    }
    return farthestNode;
}

int main() {
    // Example tree represented as an adjacency matrix
    int graph[MAX_NODES][MAX_NODES] = {0};
    // Adding edges
    graph[1][2] = graph[2][1] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[2][4] = graph[4][2] = 1;
    graph[2][5] = graph[5][2] = 1;
    graph[5][6] = graph[6][5] = 1;
    graph[5][7] = graph[7][5] = 1;

    // Starting node for BFS
    int startNode = 1;

    // Find farthest node using BFS
    int farthest = farthestNodeBFS(startNode, 7, graph);
    printf("Farthest node using BFS from node %d: %d\n", startNode, farthest);

    return 0;
}