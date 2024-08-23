#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

// Structure to represent an edge in the graph
typedef struct {
    int src, dest, weight;
} Edge;

// Function to print the shortest distance from source to all vertices
void printDistances(int dist[], int V) {
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("%d \t\t %s\n", i, "INF");
        else
            printf("%d \t\t %d\n", i, dist[i]);
    }
}

// Bellman-Ford algorithm to find the shortest path from src to all other vertices
void bellmanFord(int V, int E, Edge edges[], int src) {
    int dist[V];

    // Step 1: Initialize distances from src to all other vertices as INFINITE
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;
    
    // Step 2: Relax all edges |V| - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    // Print the calculated shortest distances
    printDistances(dist, V);
}

int main() {
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph

    // Define the edges of the graph
    Edge edges[E];
    edges[0] = (Edge){0, 1, -1};
    edges[1] = (Edge){0, 2, 4};
    edges[2] = (Edge){1, 2, 3};
    edges[3] = (Edge){1, 3, 2};
    edges[4] = (Edge){1, 4, 2};
    edges[5] = (Edge){3, 2, 5};
    edges[6] = (Edge){3, 1, 1};
    edges[7] = (Edge){4, 3, -3};

    int src = 0; // Source vertex

    // Run the Bellman-Ford algorithm
    bellmanFord(V, E, edges, src);

    return 0;
}
