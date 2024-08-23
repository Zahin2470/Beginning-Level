#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Function to perform DFS and find the farthest node
void DFS(int u, int n, int graph[MAX_NODES][MAX_NODES], int visited[], int depth, int *maxDepth, int *farthestNode) {
    visited[u] = 1; // Mark the current node as visited
    // Traverse all the adjacent nodes of the current node 'u'
    for (int v = 1; v <= n; ++v) {
        if (graph[u][v] && !visited[v]) { // If there is an edge and the adjacent node is not visited
            // Recursive DFS call
            DFS(v, n, graph, visited, depth + 1, maxDepth, farthestNode);
        }
    }
    // Update farthest node if necessary
    if (depth > *maxDepth) {
        *maxDepth = depth;
        *farthestNode = u;
    }
}

int farthestNodeDFS(int start, int n, int graph[MAX_NODES][MAX_NODES]) {
    // Initialize an array to keep track of visited nodes
    int visited[MAX_NODES] = {0};
    int maxDepth = 0;
    int farthestNode = start;
    // Perform DFS starting from the given starting node
    DFS(start, n, graph, visited, 0, &maxDepth, &farthestNode);
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

    // Starting node for DFS
    int startNode = 1;

    // Find farthest node using DFS
    int farthest = farthestNodeDFS(startNode, 7, graph);
    printf("Farthest node using DFS from node %d: %d\n", startNode, farthest);

    return 0;
}