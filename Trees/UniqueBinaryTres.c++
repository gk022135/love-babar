//leetode 96
// you hav given an interger n you have exaclty n node in binary than how many unique binary trees are possible

//note foloow rule of BST

/*
note node are made acording to BST left mein smaller right mein grater
step 1:- base case f(0) = 1 //n= 0 so only one node
f(1) = 1;
f(2) =2;
f(n) = f(0) + f(1) + f(2) +....+f(n-1);
step 2:- above steps for different element consider as root node(like n=3 possible root = 1,2,3)

f(n) = E f(i-1)*f(n-i)
*/

#include<iostream> 
#include<vector>

using namespace std;

class Solution{
    public:
    //reursive approach
    int numBinaryTree(int n){
        if(n<=1) return 1;

        int ans = 0;
        for(int i=1; i<=n; i++){
            ans = ans + numBinaryTree(i-1) * numBinaryTree(n-i);
        }
        return ans;
    }
    //doing with dp -- top down-dp(memoiaztion)

    int dpSolve(int n, vector<int>dp){
        if(n<=1) return 1;
        if(dp[n] != -1) return dp[n];

        int ans = 0;
        for(int i=1; i<=n; i++){
            ans = ans + dpSolve(i-1,dp) * dpSolve(n-i,dp);
        }
        return dp[n] = ans;

    }
    int SolveTabulation(int n){
        vector<int> dp(n+1,-1);
        dp[0] = dp[1] + 1;
    }
};

int main(){
    int n;
    cout<<"enter number of node: ";
    cin>>n;
    vector<int>dp(n+1,-1);
    Solution obj;
    cout<<"solution by recursion approach\n";
    cout<<obj.numBinaryTree(3)<<endl;


    cout<<"solution by dp approach\n";
    cout<<obj.dpSolve(3,dp)<<endl;
    return 0;
}