// left point pattern

#include<iostream>
using namespace std;
int main(){
    int size;
    cout<<"enter size of "<<endl;
    cin>>size;

    for(int i=1;i<=size;i++){

     for(int j=size-i; j>=1;j--){
        cout<<" ";

     }for(int j=1;j<=i;j++){
        cout<<"*";

     }
     cout<<endl;
    }
// se cond half of code

   for(int i=size-1;i>=1;i--){

     for(int j=size-i; j>=1;j--){
        cout<<" ";

     }for(int j=1;j<=i;j++){
        cout<<"*";

     }
     cout<<endl;
    }
}