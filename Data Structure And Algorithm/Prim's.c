#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 20  // Maximum number of vertices in the graph

// Function to find the vertex with the minimum key value
int minKey(int key[], int mstSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Prim's algorithm for MST
void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    int parent[V];  // Array to store the constructed MST
    int key[V];     // Key values used to pick the minimum weight edge
    int mstSet[V];  // Boolean array to represent vertices included in MST

    // Initialize all keys as INFINITE and MST set as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;  // MST set initially empty
    }

    key[0] = 0;  // Starting with the first vertex
    parent[0] = -1;  // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet processed
        int u = minKey(key, mstSet, V);

        // Include the picked vertex in the MST set
        mstSet[u] = 1;

        // Update the key and parent values of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update the key and parent if graph[u][v] is smaller than the key[v]
            // and v is not in the MST set
            if (graph[u][v] != -1 && mstSet[v] == 0 && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the edges of the MST
    printf("Edge \t Weight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t %d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    int V, E;

    // Take input for number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // Initialize graph with -1 (no edges)
    int graph[MAX_VERTICES][MAX_VERTICES];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = -1;
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

    // Call Prim's algorithm to calculate MST
    primMST(graph, V);

    return 0;
}
