#include <iostream>
#include <vector>
#include <algorithm> // For max
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *InsertInBT(Node *root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }

    if (data < root->data) {
        root->left = InsertInBT(root->left, data);
    } else {
        root->right = InsertInBT(root->right, data);
    }
    return root;
}

pair<int, int> HeightBST(Node *root) {
    if (root == nullptr) {
        return {0, 0}; // Base case: both heights are 0
    }

    int leftHeight = 1 + HeightBST(root->left).first;
    int rightHeight = 1 + HeightBST(root->right).second;

    return {leftHeight, rightHeight};
}

int main() {
    vector<int> datas = {10, 5, 15, 3, 7};
    Node *root = nullptr;

    for (int i : datas) {
        root = InsertInBT(root, i);
    }

    pair<int, int> heights = HeightBST(root);

    cout << "Height of left subtree: " << heights.first << endl;
    cout << "Height of right subtree: " << heights.second << endl;

    return 0;
}
