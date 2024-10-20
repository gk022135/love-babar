//inverted pyramid

#include<iostream>
using namespace std;

int main(){
    int size;
    cout<<"emter size "<<endl;

    cin>>size;

    for(int i=size-1;i>=1;i--){

    for(int j=1;j<size-i;j++){
        cout<<" ";
    }
    for(int j=1;j<=2*i-1;j++)
    {
        cout<<"*";
    }
    cout<<endl;
   }
   return 0;
}