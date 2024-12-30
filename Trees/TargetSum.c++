// you have give tree your task is to check weather traversing it form top leaf sum of data equal to target or not

#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
      int  data;
      Node* left;
      Node* right;

      Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;

      }
};
Node* InsertInBT(Node* root, int data){
    if(root == nullptr) {
        return new Node(data);
    }
    if(data < root->data){
        root->left =  InsertInBT(root->left,data);
    }
    else{
        root->right = InsertInBT(root->right, data);
    }
    return root;

}

bool TargetSum(Node* root, int target){
    if(root == nullptr) return false;
    if(root->left == nullptr && root->right == nullptr){
        return target == root->data;
    }

    int newTarget = target - root->data;

    return TargetSum(root->left,newTarget) || TargetSum(root->right, newTarget);
}

int main(){
    vector<int> datas = {5,4,8,11,0,13,4,22,2,0,0,0,1};
    int target = 22;
    Node* root = nullptr;

    for(int i : datas){
        root = InsertInBT(root,i);
    }
    cout<<"given Target element equal "<<TargetSum(root,target)<<endl;
    return 0;
}