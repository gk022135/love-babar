//first traversal method BFS (Breadth first Search)
//tc = O(b^d);
//sc = O()

/*
<------ Approach ---->
Data Types Required:

1. queue<int> for BFS traversal.

2. unordered_map<int, bool> (or vector<bool>) to keep track of visited nodes.

3. unordered_map<int, list<int>> (or vector<vector<int>>) to represent the adjacency list.

## Steps:

1. Initialize a queue<int> for BFS traversal.
2. Create a visited map or array to mark nodes as visited, initialized to false for all nodes.

3. Enqueue the starting node and mark it as visited.
4.While the queue is not empty:

   a. Dequeue a node from the queue and process it.
   b. Traverse  all adjacent nodes of the dequeued node:
        1. If an adjacent node is unvisited:
           a. Enqueue it.
           b. Mark it as visited.

5. Repeat until all reachable nodes are processed.

6. If the graph is disconnected, repeat the process for unvisited nodes to ensure complete traversal.
*/


#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>

using namespace std;

void prepairAdjList(unordered_map<int, list<int>>&adjList, vector<pair<int, int>>&edges){
    for(int i =0;i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}
void bfs2(unordered_map<int,list<int>>&adjList, unordered_map<int, bool>&visited, vector<int>&ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] == 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        //
    }

}

vector<int> bfs(int vertex, vector<pair<int, int>>edges){
    unordered_map<int, list<int>>adjList;
    vector<int>ans;

    unordered_map<int, bool>visited;

    prepairAdjList(adjList, edges);
    //traverse ll components of grapha

    for(int i =0; i<=vertex; i++){
        if(!visited[i]){
            bfs2[adjList, visited, ans, i];
        }
    }
}