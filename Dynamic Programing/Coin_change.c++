#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class Solution{
public: 
    int solveRecursion(vector<int>&coin,int amount){
        if(amount == 0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }

        int mini = INT_MAX;
        for(int i =0;i<coin.size();i++){
            int ans = solveRecursion(coin,amount-coin[i]);
            if(ans != INT_MAX){
                // cout<<coin[i]<<" ";
                mini = min(mini,ans+1); // because remember we use a coin to move toward zero
            }
        }
        return mini;
    }




     int topDown(vector<int>&coin,int amount,vector<int>&dp){
        if(amount == 0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        if(dp[amount] != -1){
            return dp[amount];

        }

        int mini = INT_MAX;
        for(int i =0;i<coin.size();i++){
            int ans = topDown(coin,amount-coin[i],dp);
            if(ans != INT_MAX){
                // cout<<coin[i]<<" ";
                mini = min(mini,ans+1); // because remember we use a coin to move toward zero
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }

    int coinChange(vector<int>&coin,int amount){
        int n = coin.size();
        vector<int>dp(amount+1,-1);
        int ans = solveRecursion(coin,amount);
        int top = topDown(coin,11,dp);
        if(ans == INT_MAX) return -1;

        cout<<"topdown answer "<<top<<endl;
        cout<<"recursion ans "<<ans<<endl;

        return ans;

    }
   
};

int main(){
    vector<int>coin = {1,2,5};
    int amount = 11;
    Solution sol;
    cout<<"ans is "<<sol.coinChange(coin,11)<<endl;
   
}