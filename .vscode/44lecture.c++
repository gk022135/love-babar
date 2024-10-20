#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector<int>arr{0,1,0,0,0,1,0,0,0,1,0,1,0};
    int end = arr.size()-1;
    int i=0;
    int start = 0;

    while(start<end){
        if(arr[start]==0){start++;}
        if(arr[end]==1){end--;}
        if(arr[start]==1 && arr[end]==0){
            swap(arr[start],arr[end]);
            start++;end--;
        }
    }
    for(auto value:arr){
        cout<<value<<",";
    }
}