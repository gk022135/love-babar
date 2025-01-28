// implementing  Graph using Adjacency matrix 
//But here the Node having some values like (20,3,40,-45,12)

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class GraphWithNodeValue{
    private:
       int Num_of_nodes;
       vector<vector<int>>Adj_mat;
       unordered_map<int, int>Node_value;
    
    public:
       GraphWithNodeValue(int Node_Num){
        Num_of_nodes = Node_Num;
        Adj_mat.resize(Node_Num, vector<int>(Node_Num, 0));
       }

       void addEdge(int start, int end, bool undirected = true){
         Adj_mat[start][end] = 1;
         if(undirected){
            Adj_mat[end][start] = 1;
         }

       }
       void AddNodeVal(int index, int val){
        Node_value[index] = val;
       }

       void PrintAdj_Mat(){
          cout<<"here is your Adjacency matrix:-";

          for(int i=0; i<Num_of_nodes; i++){
            for(int j=0; j<Num_of_nodes; j++){
                cout<<Adj_mat[i][j] <<" ";
            }
            cout<<endl;
          }

       }
};


int main(){
    int nodes, edges;

    cout<<"enter number of nodes in your graph:";
    cin>>nodes;

    GraphWithNodeValue g(nodes);
    
    cout<<"enter value regarding coresspondind nodes(i.e 0 --> 209)";
    for(int i =0; i<nodes; i++){
        int val, nodes_num;
        cin>>nodes_num>> val;
        g.AddNodeVal(nodes_num,val);
    }

    cout<<"enter the number of edges in graph ";
    cin>>edges;

    for(int i =0; i<edges; i++){
        int start, end;
        cout<<"enter the start and end: ";
        cin>>start>>end;
        g.addEdge(start,end);
    }

    g.PrintAdj_Mat();

    return 0;
    
}