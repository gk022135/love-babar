// Creating a graph and making BFS traversal

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

class GraphMaking {
private:
    unordered_map<int, list<int>> adj_list;
    int num_node;

public:
    GraphMaking(int nodes) {
        num_node = nodes;
    }

    // Making adjacency list
    void insertAdj_List(int u, int v, int isDirected, int index) {
        adj_list[u].push_back(v);
        if (!isDirected) {
            adj_list[v].push_back(u);
        }
    }

    void printing_Adj_list() {
        for (auto i : adj_list) {
            cout << i.first << " --> { ";
            for (auto x : i.second) {
                cout << x << ", ";
            }
            cout << "}" << endl;
        }
    }

    // BFS traversal on created adjacency list
    vector<vector<int>> BFS_Traversal(vector<int>& visited, int node_to_traverse) {
        visited[node_to_traverse] = 1;
        queue<int> que;
        que.push(node_to_traverse);

        vector<vector<int>>result;

        

        while (!que.empty()) {
            int tempNode = que.front();
            que.pop();
            vector<int> temp;
            

            for (auto x : adj_list[tempNode]) {
                if (!visited[x]) {
                    visited[x] = 1;
                    que.push(x);
                    temp.push_back(x);
                }
            }
            result.push_back(temp);
        }
        return result;
    }

    void printBFS(vector<vector<int>>& result) {
        cout << "[ ";
        for (auto i : result) {
            cout << "[ ";
            for (auto x : i) {
                cout << x << ", ";
            }
            cout << "]" ;
        }
        cout << "]" << endl;
    }
};

// Driver function
int main() {
    cout << "--- Enter number of nodes in your graph ----\n";
    int nums_nodes;
    cin >> nums_nodes;

    GraphMaking obj = GraphMaking(nums_nodes);

    cout << "--- Enter the number of edges in your graph ----\n";
    int edges;
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        cout << "Enter the corresponding edge pair (u v): \n";
        int u, v;
        cin >> u >> v;
        obj.insertAdj_List(u, v, 0, i);
    }

    // Printing adjacency list
    cout << "-------- Adjacency List --------\n";
    obj.printing_Adj_list();

    cout << "-------- Making BFS Traversal --------\n";

    vector<int> visited(nums_nodes, 0);
    vector<vector<int>> result;

    for (int i = 0; i < visited.size(); i++) {
        if (!visited[i]) {
            result = obj.BFS_Traversal(visited, i);
        }
    }

    // Printing BFS output for the given adjacency list
    cout << "------- BFS Traversal Result -------\n";
    obj.printBFS(result);
    return 0;
}
