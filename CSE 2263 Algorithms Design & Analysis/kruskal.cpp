#include <bits/stdc++.h>
using namespace std;

int parent[100];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}


bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2]; 
}

int main() {
    int n = 4;

    
    vector<vector<int>> edges = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };

    sort(edges.begin(), edges.end(), cmp);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int total = 0;

    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        int pu = find(u);
        int pv = find(v);

        if (pu != pv) {
            cout << u << " - " << v << " : " << w << endl;
            total += w;
            parent[pu] = pv;
        }
    }

    cout << "Total = " << total;

    return 0;
}
