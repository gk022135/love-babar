#include <iostream>
#include <vector>

using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    // Constructor
    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to build the tree
node* buildTree(node* root) {
    cout << "Enter the data  ";
    int data;
    cin >> data;

    // Base case: if data is -1, return NULL
    if (data == -1) {
        return NULL;
    }

    // Create a new node with the input data
    root = new node(data);

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

int main() {
    node* root = NULL;

    // Creating tree
    root = buildTree(root);

    return 0;
}

// love babar lecturre 62 18:10