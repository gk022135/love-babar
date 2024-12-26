// Searching an element in binary tree

//step for creating Binary Tree
//Step 1.--> Create a class Node  and make variable data and two pointers left and right
//Step 2.--> Create a Insert Fuction for insertion in BT retrun Type of This function Should be Node*  and pass two args 1st Node* root, 2nd Data

//Step3 --> inside insertion function write three condtions if root == nullptr
//data < root->data



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


Node* InsertBst(Node* root, int data){
    if(root == nullptr){
        return new Node(data);
    }
    if(data < root->data){
        root->left = InsertBst(root->left, data);
    }
    else{
        root->right = InsertBst(root->right, data);
    }
    return root;
}

//searching your target element here
bool Inorder(Node* root, int target){
    if(root == nullptr) return false;
    if(target == root->data){
        cout<<"you got your target here bro -->"<<root->data<<" ";
        return true;
    }
    
    else if(target < root->data){
       return Inorder(root->left,target);
    }
    else{
       return Inorder(root->right,target);
    }
}

int main(){
    Node* root = nullptr;
    vector<int>bst = {10,5,15,3,7};

    for(int i : bst){
        root = InsertBst(root,i);
    }
    cout<<"searched element is here \n";
    cout<<Inorder(root,7)<<endl;
    cout<<endl;

    return 0;

}