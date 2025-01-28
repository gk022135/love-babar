#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Graph {
public:
    unordered_map<int, vector<int>> adj;

    // Function to add an edge between two nodes
    void addEdge(int u, int v) {
        adj[u].push_back(v);  // Directed graph
        adj[v].push_back(u);  // For undirected graph, add this line
    }

    // BFS traversal from a given starting node
    void bfs(int startNode) {
        unordered_map<int, bool> visited;  // To track visited nodes
        queue<int> q;                      // Queue for BFS

        q.push(startNode);                 // Enqueue the start node
        visited[startNode] = true;         // Mark it as visited

        while (!q.empty()) {
            int node = q.front();          // Get the front node
            q.pop();                       // Remove it from the queue
            cout << node << " ";           // Print the current node

            // Traverse all adjacent nodes
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);      // Enqueue unvisited neighbors
                    visited[neighbor] = true;  // Mark them as visited
                }
            }
        }
    }
};

int main() {
    Graph g;

    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int startNode;
    cout << "Enter the starting node for BFS: ";
    cin >> startNode;

    cout << "BFS Traversal starting from node " << startNode << ": ";
    g.bfs(startNode);
    cout << endl;

    return 0;
}
