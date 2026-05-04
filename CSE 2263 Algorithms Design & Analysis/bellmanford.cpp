#include <iostream>
#include <vector>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {

    const int INF = 1e8;
    vector<int> dist(V, INF);
    dist[src] = 0;

    // Relax all edges V times (last one checks negative cycle)
    for(int i = 0; i < V; i++) {

        for(int j = 0; j < edges.size(); j++) {

            int u = edges[j][0];   // source node
            int v = edges[j][1];   // destination node
            int wt = edges[j][2];  // weight

            if(dist[u] != INF && dist[u] + wt < dist[v]) {
                if(i == V - 1) return {-1};  // negative cycle detected
                dist[v] = dist[u] + wt;
            }
        }
    }
    return dist;
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {1,3,2},{4,3,-1},{2,4,1},{1,2,1},{0,1,5}
    };

    int src = 0;
    vector<int> result = bellmanFord(V, edges, src);

    for(int d : result)
        cout << d << " ";

    return 0;
}
