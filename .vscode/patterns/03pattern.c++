// right pointed pyramid

#include<iostream>
using namespace std;

int main(){
    int size;
    cout<<"enter size "<<endl;
    cin>>size;

    for(int i = 1;i<=size;i++){
        for(int j=1;j<=i;j++){
            cout<<"#";
        }
        cout<<endl;
    }
    for(int i = size-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<"#";
        }
        cout<<endl;
    }
}