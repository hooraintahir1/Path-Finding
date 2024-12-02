#include <iostream>
#include <climits>  // For INT_MAX

using namespace std;

// Function to implement Dijkstra's algorithm
void dijkstra(const int V, int graph[10][10], int source) {
    int dist[V];    // Array to store the shortest distance from source to each vertex
    bool visited[V]; // Array to track visited vertices

    // Initialize all distances to infinity and visited to false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;  // Set all distances to infinity
        visited[i] = false; // Mark all vertices as unvisited
    }

    dist[source] = 0;  // The distance to the source vertex is 0

    for (int count = 0; count < V - 1; count++) {
        // Find the vertex with the minimum distance that hasn't been visited
        int minDist = INT_MAX, u = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        // Mark the selected vertex as visited
        visited[u] = true;

        // Update the distances of the neighbors of the selected vertex
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Output the shortest distance from the source to each vertex
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            cout << "Vertex " << i << ": Unreachable" << endl;
        }
        else {
            cout << "Vertex " << i << ": " << dist[i] << endl;
        }
    }
}

int main() {
    // Number of vertices in the graph
    int V = 9;

    // Graph represented as an adjacency matrix (0 means no edge)
    int graph[10][10] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    // Source vertex
    int source = 0;

    // Run Dijkstra's algorithm from the source vertex
    dijkstra(V, graph, source);

    return 0;
}