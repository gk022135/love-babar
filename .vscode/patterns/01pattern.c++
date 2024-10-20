#include<iostream>
using namespace std;

int main(){
    int size;
    cout<<"enter size"<<endl;
    cin>>size;


    for(int i = 0;i<size;i++)
    {
       for (int j = 1; j <= size - i; j++) {
                cout<<(" ");
            }
            
            for (int j = 1; j <= i; j++) {
                cout<<("* ");
            }
        if(i == size-1){

        }
        else
           cout<<endl;
    }

    cout<<endl;
    for (int i = size-1; i >= 1; i--) {
            // inner loop to print spaces
            for (int j = 1; j <= size- i; j++) {
                cout<<(" ");
            }
            // inner loop to print stars
            for (int j = 1; j <= 2 * i - 1; j++) {
                cout<<("*");
            }
           cout<<endl;
            
        }
    }