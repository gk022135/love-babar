//comparision of two binary trees if they are same return true else return false

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

Node* insertInBinary(Node* root,int data){
    if(root == nullptr){
        return new Node(data);
    }
    if(data < root->data){
        root->left = insertInBinary(root->left, data);
    }
    else{
        root->right = insertInBinary(root->right,data);
    }

    return root;
}
void inOrderTraversal(Node* root){
    if(root == nullptr)
    {
        return ;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

bool compairsionBTs(Node* B1, Node* B2){
    if(B1 == nullptr && B2 == nullptr) return true;
    if(B1 == nullptr || B2 == nullptr) return false;

    return (B1->data == B2->data) && (B1->left ->data == B2->left->data) && (B1->right ->data == B2->right->data);

}


int main(){
    Node* root = nullptr;
    Node* root2 = nullptr;

    vector<int>bst1 = {10,5,15,3,7};
    vector<int>bst2 = {10,5,15,3,7};

    // insertion in first binary tree 
    for(int i : bst1){
        root = insertInBinary(root,i);
    }

    //insertion in second binary tree
    for(int i : bst2){
        root2 = insertInBinary(root2,i);
    }

    // traversal of both tree
    cout<<"1st Bst \n";
    inOrderTraversal(root);
    cout<<endl;

    // traversal of second binary tree
    cout<<"inorder Travesal of 2nd Bst \n";
    inOrderTraversal(root2);
    cout<<endl;

    cout<<"checking weahter both tree are same or not\n";
    cout<<compairsionBTs(root,root2);
    cout<<endl;
    
 return 0;
}