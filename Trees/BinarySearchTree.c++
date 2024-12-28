//inserting data of sorted array in Binary tree == Binary Search tree

#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
      int data;
      Node* left;
      Node* right;

      Node(int data){
         this->data = data;
         this->left = nullptr;
         this->right = nullptr;

      }

};

Node* InsertBST(vector<int> &vec, int start, int end){
    if(start>end) return nullptr;

    int mid = start + (end - start)/2;

    Node* root = new Node(vec[mid]);
    
    root->left = InsertBST(vec,start,mid-1);
    root->right = InsertBST(vec,mid+1,end);

    return root;
}
void INorderTravesal(Node* root){
    if(root == nullptr) return ;

    INorderTravesal(root->left);
    cout<<root->data<<", ";
    INorderTravesal(root->right);
}

int main(){
    vector<int> vec = {-10,-9,0,3,5,6};

    Node* root = nullptr;


    cout<<"onserting in Binary serch tree\n";
    root =  InsertBST(vec,0,5);

    cout<<"traversal of Binary  search tree\n";
    INorderTravesal(root);
    return 0;
}