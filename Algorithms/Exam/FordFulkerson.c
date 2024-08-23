#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

#define V 6  // Number of vertices in the given graph

// A function to perform BFS and find an augmenting path
bool bfs(int rGraph[V][V], int s, int t, int parent[]) {
    // Create a visited array and mark all vertices as not visited
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    // Create a queue, enqueue source vertex and mark it as visited
    int queue[V];
    int front = 0, rear = 0;

    queue[rear++] = s;
    visited[s] = true;
    parent[s] = -1;

    // Standard BFS loop
    while (front < rear) {
        int u = queue[front++];

        for (int v = 0; v < V; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                // If we find a connection to the sink node, then there is no point in BFS anymore. We just need to set its parent and return true
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    // We didn't reach the sink in BFS starting from the source, so return false
    return false;
}

int fordFulkerson(int graph[V][V], int s, int t) {
    int u, v;

    int rGraph[V][V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V]; 
    int max_flow = 0;

    while (bfs(rGraph, s, t, parent)) {

        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            if (path_flow > rGraph[u][v])
                path_flow = rGraph[u][v];
        }

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int graph[V][V] = { { 0, 16, 13, 0, 0, 0 },
                        { 0, 0, 10, 12, 0, 0 },
                        { 0, 4, 0, 0, 14, 0 },  
                        { 0, 0, 9, 0, 0, 20 },
                        { 0, 0, 0, 7, 0, 4 },   
                        { 0, 0, 0, 0, 0, 0 } };

    int source = 0;  // Source is node S (index 0)
    int sink = 5;    // Sink is node T (index 5)

    printf("The maximum possible flow is %d\n", fordFulkerson(graph, source, sink));

    return 0;
}