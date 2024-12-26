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
        this ->left = nullptr;
        this ->right = nullptr;

    }
};

Node* insert(Node* root,int data){
    if(root == nullptr){
        return new Node(data);
    }

    if(data < root->data){
        root -> left = insert(root ->left,data);
    }
    else {
        root->right = insert(root->right,data);
    }
    return root;
}

void inorder(Node* root){
    if(root == nullptr) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void preorder(Node* root){
    if(root == nullptr) return ;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == nullptr) return ;


    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    vector<int>trees = {10,2,4,2,30,5,20,12,50};
    Node* root = nullptr;

    root = insert(root, 10);
    root = insert(root,5);
    root = insert(root,15);
    root = insert(root,3);
    root = insert(root,7);


    // //if you want to insert data into trees by it self than follow this
    //  // Insert all elements of the vector into the binary tree
    // for (int i = 0; i < trees.size(); i++) {
    //     root = insert(root, trees[i]);
    // }


    cout<<"inorder Traversal: \n";
    inorder(root);
    cout<<endl;

    cout<<"preorder Traversal\n";
    preorder(root);
    cout<<endl;

    cout<<"postorder traversal \n";
    postorder(root);
    cout<<endl;

    return 0;


}