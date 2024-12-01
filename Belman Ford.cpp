#include <iostream>
#include <vector>
#include <limits>
using namespace std;


struct Edge {
    int source, destination, weight;
};


void bellmanFord(int vertices, int edges, vector<Edge> &graph, int source) {
 
    vector<int> distance(vertices, numeric_limits<int>::max());
    distance[source] = 0;

   
    for (int i = 0; i < vertices - 1; ++i) {
        for (int j = 0; j < edges; ++j) {
            int u = graph[j].source;
            int v = graph[j].destination;
            int weight = graph[j].weight;

            if (distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    
    for (int j = 0; j < edges; ++j) {
        int u = graph[j].source;
        int v = graph[j].destination;
        int weight = graph[j].weight;

        if (distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
            cout << "Graph contains a negative weight cycle." << endl;
            return;
        }
    }

   
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < vertices; ++i) {
        cout << i << "\t" << (distance[i] == numeric_limits<int>::max() ? "INF" : to_string(distance[i])) << endl;
    }
}

int main() {
    
    int vertices = 5, edges = 8;
    vector<Edge> graph = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };
    int source = 0;

    bellmanFord(vertices, edges, graph, source);

    return 0;
}
