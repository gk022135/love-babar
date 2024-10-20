// hollow diamond pattern

#include<iostream>
using namespace std;

int main(){
    int size;
    cout<<"enter  size "<<endl;
    cin>>size;

    for(int i= 0;i<size ;i++){
        for(int j=0;j<i;j++){
            if(j==size-1-i){
                cout<<"*";
            }else{
                cout<<" ";
            }

        }
    }
}