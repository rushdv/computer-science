#include<bits/stdc++.h>
using namespace std;

#define V 6   // Number of vertices in the graph

int findMinDistance(vector<int>& distance, vector<bool>& visited) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && distance[v] <= min) {
            min = distance[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void dijkstra(int graph[V][V], int start) {
    vector<int> distance(V, INT_MAX);  // holds shortest distance from start
    vector<bool> visited(V, false);    // keeps track of visited nodes

    distance[start] = 0; // distance from start to itself is 0

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = findMinDistance(distance, visited);
        visited[u] = true;

        // Update distance of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && distance[u] != INT_MAX
                && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    // Print the result
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t" << distance[i] << endl;
}

int main() {
    // Example graph (adjacency matrix)
    int graph[V][V] = {
        {0, 7, 9, 0, 0, 14},
        {7, 0, 10, 15, 0, 0},
        {9, 10, 0, 11, 0, 2},
        {0, 0, 11, 0, 6, 0},
        {0, 0, 0, 6, 0, 9},
        {14, 0, 2, 0, 9, 0}
    };

    int start = 0;
    dijkstra(graph, start);

    return 0;
}

