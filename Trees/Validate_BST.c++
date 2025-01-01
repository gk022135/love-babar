// leetCode 98
// validate binary tree

#include<iostream>
#include<limits.h>
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

class Solution{
    public:
    bool valdateBST(Node* root, int mini, int maxi){
        if(root == nullptr) return true;

        if(root->data <= mini || root->data >= maxi) return false;

        return (valdateBST(root->left, mini,root->data)) && (valdateBST(root-> right, root->data,maxi));
    }

};

Node* InsertionInBST(Node* root,int data){
    if(root == nullptr){
        return new Node(data);
    }
    if(data < root->data){
        root->left = InsertionInBST(root->left, data);
    }
    else{
        root->right = InsertionInBST(root->right, data);
    }
    return root;
}

int main(){
    vector<int>arr = {5,1,4,NULL,NULL,3,6};
    Solution obj;
    Node* root = nullptr;

    for(int i : arr){
        root = InsertionInBST(root,i);
    }
    cout<<endl;
    cout<<"given data is for valid binary search tree "<<obj.valdateBST(root,INT_MIN, INT_MAX)<<"\n";
}


//implementation done successefully