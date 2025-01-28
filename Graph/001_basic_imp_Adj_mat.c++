// implementing graph using Adjancency matrix node having no values just marked from zero to n-1

#include<iostream>
#include<vector>

using namespace std;

class Graph{
    private:
       vector<vector<int>>adjanencyMat;
       int NumberOfNodes;
    
    public:
       Graph(int Num_of_Nodes){
        NumberOfNodes = Num_of_Nodes;
        adjanencyMat.resize(Num_of_Nodes, vector<int>(Num_of_Nodes, 0));

       }
       void addEdge(int start, int end, bool undirect = true){
            adjanencyMat[start][end] = 1;
            if(undirect){
                adjanencyMat[start][end] = 1;
            }
       }
       void PrintAdja_Mat(){
        cout<<"adjacency matrix \n";

        for(int i = 0;i<NumberOfNodes; i++){
            for(int j =0; j<NumberOfNodes; j++){
                cout<<adjanencyMat[i][j]<<" ";
            }
            cout<<endl;
        }
       }

};

int main(){
    int Num_nodes, edges;

    cout<<"enter the number of Nodes: ";
    cin>>Num_nodes;

    Graph g(Num_nodes);

    cout<<"enter number of edges you have in your graph: ";
    cin>> edges;

    for(int i =0; i<edges; i++){
        int start,end;
        cout<<"enter the start and end of edge of graph: ";
        cin>>start>>end;

         g.addEdge(start,end);
    }
    g.PrintAdja_Mat();

    return 0;
}