#include<iostream>
#include<vector>

using namespace std;


class Solution{
    public :
          int missingNumber(vector<int> &nums,int n){
            

            vector<int>record(n+1,0);

            for(auto i : nums){
                record[i]++;
            }
            for(int i =1;i<=n;i++){
                if(record[i] == 0) return i;
            }
            return -1;

          }
          int missingByXor(vector<int>&nums,int n){
            int xor1=0;
            int xor2=0;
            for(int i =0;i<n-1;i++){
                xor1 = xor1^nums[i];
                xor2 = xor2^(i+1);
            }
            return xor1^xor2^n;
          }

          int sumOfAll(vector<int>&nums,int n){
            int sum1 = 0;
            int sum2 = 0;
            for(auto i : nums){
                sum1 = sum1 + i;
            }

            for(int i = 1;i<=n+1;i++){
                sum2 = sum2 + i;
            }
            return abs(sum2-sum1);
          }

};


int main(){
    vector<int>nums = {1,2,3,4,6};
    Solution sol;
    cout<<sol.missingNumber(nums,5)<<endl;
    cout<<sol.missingByXor(nums,5)<<endl;
    cout<<sol.sumOfAll(nums,5)<<endl;

}