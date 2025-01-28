// Implementation of graph using adjacency list

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>  // Added for storing values associated with nodes

using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adj;
    unordered_map<int, int> nodeValues;  // Store values associated with nodes

    void addEdge(int u, int v, bool direction) {
        // direction == 0 means undirected graph
        // direction == 1 means directed graph

        adj[u].push_back(v);
        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    void setNodeValue(int node, int value) {
        nodeValues[node] = value;
    }

    void printAdjList() {
        for (auto i : adj) {
            cout << i.first << " (Value: " << nodeValues[i.first] << ") --> ";
            for (auto j : i.second) {
                cout << j << " (Value: " << nodeValues[j] << "), ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of nodes:" << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges:" << endl;
    cin >> m;

    Graph obj;

    cout << "Enter values for each node:" << endl;
    for (int i = 1; i <= n; i++) {
        int value;
        cout << "Value for node " << i << ": ";
        cin >> value;
        obj.setNodeValue(i, value);
    }

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // Here, u and v represent the endpoints of an edge connecting node u to node v.
        // Creating an undirected graph
        obj.addEdge(u, v, 0);
    }

    cout << "\nAdjacency List with Node Values:" << endl;
    obj.printAdjList();

    return 0;
}
