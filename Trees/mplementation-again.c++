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
Node* insertIntoBinary(Node* root,int data){
    if(root == nullptr){
        return new Node(data);
    }

    if(data < root->data){
        root->left = insertIntoBinary(root->left ,data);
    }
    else{
        root->right = insertIntoBinary(root->right,data);
    }
    return root;
}

void InorderTraversal(Node* root){
    if(root == nullptr) return;

    InorderTraversal(root->left);
    cout<<root->data<<" ";
    InorderTraversal(root->right);
}

void PreorderTraversal(Node* root){
    if(root == nullptr){
        return;
    }
    cout<<root->data<<" ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);

}
void PostorderTraversal(Node* root){
    if(root == nullptr){
        return;
    }
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node* root = nullptr;
    vector<int>bst_data = {1,2,4,23,6,823,6,83,32};

    for(int i : bst_data){
        root = insertIntoBinary(root,i);
    }
    cout<<"inorder traversal of Binary tree\n";
    InorderTraversal(root);
    cout<<endl;

    cout<<"preorder Binary tree traversal\n";
    PreorderTraversal(root);
    cout<<endl;

    cout<<"postOrder Binary tree traveersal\n";
    PostorderTraversal(root);
    cout<<endl;

    return 0;

}