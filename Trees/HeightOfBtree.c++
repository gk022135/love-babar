// finding height of binary tree (also height of left and right binary tree);

#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *InsertInBT(Node *root, int data)
{
    if (root == nullptr)
    {
        return new Node(data);
    }

    if (data < root->data)
    {
        root->left = InsertInBT(root->left, data);
    }
    else
    {
        root->right = InsertInBT(root->right,data);
    }
    return root;
}

int HeightBST(Node *root)
{
    if (root == nullptr)
        return 0;

    int leftTreeHeight = HeightBST(root->left);
    int rightTreeheight = HeightBST(root->right);

    
    cout << "height of left Binary tree is " << leftTreeHeight << endl;
    cout << "height of right Binary tree is " << rightTreeheight << endl;

    return 1+max(leftTreeHeight ,rightTreeheight);
}

int main(){
    vector<int> datas = {10,5,15,3,7};
    Node* root = nullptr;

    for(int i : datas){
        root = InsertInBT(root,i);
    }
    cout<<"maximum height of binary tree is "<<HeightBST(root)<<endl;
    return 0;
}