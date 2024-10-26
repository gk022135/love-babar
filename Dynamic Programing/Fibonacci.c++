#include<iostream>
#include<vector>

using namespace std;

int fibnacci(int n){
    if(n ==0) return 0;
    if(n == 1 || n ==2) return 1;

    int ans = fibnacci(n-1)+fibnacci(n-2);
    return ans;
}

// top down approach
int fibDp(int n,vector<int>&dp){
    if(n==0 || n == 1) return n;

    if(dp[n] !=-1){
        return dp[n];
    }
    dp[n] = fibDp(n-1,dp)+fibDp(n-2,dp);
    return dp[n];

}

//bottom up appproach  no recursion is used
int BottomUp(int n,vector<int>dp){
    if(n==0){
        dp[0] = 0;
    }
    if(n==1){
        dp[1] =1;
    }

    for(int i = 2;i<n+1;i++){
        dp[i] = dp[i-1] + dp[i-2];

    }
    return  dp[n];

}
int main(){
    int n=9;
    vector<int>dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    int ans = fibDp(n,dp);
    cout<<ans<<endl;

    cout<<BottomUp(n,dp)<<endl;


   // cout<<fibnacci(7)<<endl;
    return 0;

}