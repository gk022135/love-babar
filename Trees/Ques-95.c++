/*Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
*/
#include<iostream>
#include<vector>
#include<map>

using namespace std;

class TreeNode{
    public:
      int data;
      TreeNode* left;
      TreeNode* right;

      TreeNode(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
      }
};

class Solution{
    public:
       vector<TreeNode* >solve(int start, int end){
        if(start >end){
            return {NULL};
        }
        if(start == end){
            TreeNode* root = new TreeNode(start);
            return {root};
        }
        vector<TreeNode *>result;
        
        for(int i = start; i<=end; i++){
            vector<TreeNode* >left_bst = solve(start, i-1);
            vector<TreeNode* >right_bst = solve(i+1, end);

            for(TreeNode* leftRoot : left_bst){
                for(TreeNode* rightRoot : right_bst){
                    TreeNode* root = new TreeNode(i);
                    root->left = leftRoot;
                    root->right = rightRoot;

                    result.push_back(root);
                }
            }
        }
        return result;

       }
       vector<TreeNode* > generateTrees(int n){
        return solve(1,n);
       }
};
TreeNode* inorder(TreeNode* root){
    if(root == nullptr) return NULL;

    root->left = inorder(root->left);
    cout<<root->data<<", ";
    root->right = inorder(root->right);

    return root;

}

int main(){
    int n =3;
    Solution obj;
    vector<TreeNode* > res;

    res = obj.generateTrees(n);

    for(TreeNode* i : res){
        cout<<inorder(i);
        cout<<endl;
    }
    cout<<endl;
    return 0;
}

