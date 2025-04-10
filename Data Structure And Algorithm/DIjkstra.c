//Dijkstra Algorithm
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 20 // Maximum number of vertices in the graph

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int sptSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int V, int src) {
    int dist[V]; // Array to store the shortest distance from the source
    int sptSet[V]; // Shortest path tree set (true if vertex is included in shortest path tree)
    
    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0; // Distance from source to itself is 0

    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet, V);

        // Mark the picked vertex as processed
        sptSet[u] = 1;

        // Update dist[] for the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update the distance if v is not processed yet and there is an edge from u to v
            if (!sptSet[v] && graph[u][v] != INT_MAX && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the shortest distance from the source
    printf("Vertex\t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            printf("%d\t INF\n", i);
        } else {
            printf("%d\t %d\n", i, dist[i]);
        }
    }
}

int main() {
    int V, E, src;
    
    // Take input for number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // Initialize graph with INT_MAX (representing no edges)
    int graph[MAX_VERTICES][MAX_VERTICES];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    // Take input for number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    // Take input for each edge and its weight
    printf("Enter the edges (format: u v weight):\n");
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);

        // As it's an undirected graph, add the edge in both directions
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    // Take input for the source vertex
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    // Call Dijkstra's algorithm
    dijkstra(graph, V, src);

    return 0;
}
