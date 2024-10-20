// union of two arr

#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int>arr1{1,2,3,4,4,5};
    vector<int>arr2{5,5,5,9};
    vector<int>uni;
    int j=0;

    for(int i =0;i<arr1.size();i++){
        for(int j=0;j<arr2.size();j++){
            if(arr1[i]==arr2[j]){ 
                arr2[j] = -1;
            }
        }
    }
    for(int i=0;i<arr2.size();i++)
       if(arr2[i]!= -1){
       arr1.push_back(arr2[i]);}

    for(auto val:arr1){
        cout<<val<<",";
    }
}