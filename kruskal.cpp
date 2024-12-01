#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Edge {
    int src, dest, weight;

    
    bool operator<(const Edge &other) const {
        return weight < other.weight;
    }
};


class DSU {
private:
    vector<int> parent, rank;

public:
   
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

   
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};


void kruskalMST(int vertices, vector<Edge> &edges) {
   
    sort(edges.begin(), edges.end());

    DSU dsu(vertices);

    vector<Edge> mst; 
    int mstWeight = 0;

    for (const auto &edge : edges) {
        if (dsu.find(edge.src) != dsu.find(edge.dest)) {
            dsu.unionSets(edge.src, edge.dest);
            mst.push_back(edge);
            mstWeight += edge.weight;
        }
    }

   
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (const auto &edge : mst) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << "\n";
    }
    cout << "Total weight of MST: " << mstWeight << "\n";
}

int main() {
   
    int vertices = 4; 
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {1, 2, 2},
        {2, 3, 4}
    };

    kruskalMST(vertices, edges);

    return 0;
}
