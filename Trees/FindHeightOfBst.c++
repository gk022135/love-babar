// program for finding height of binary tree

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
Node* insertionInBT(Node* root, int data){
    if(root == nullptr) return new Node(data);

    if(data < root ->data){
        root->left = insertionInBT(root->left, data);
    }
    else{
        root->right = insertionInBT(root->right, data);
    }

    return root;
}

int main(){
    vector<int>datas = {10,5,15,3,7};

    Node* root = nullptr;

    for(int i : datas){
        root = insertionInBT(root,i);
    }
}