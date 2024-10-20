#include<iostream>
using namespace std;

int factorial(int num){
    if(num == 0 || num == 1)
       return 1;

 return num*factorial(num-1);
}

int primeNumber(int num){
    
}

int main(){
    int result;
    result = factorial(10);
    cout<<result<<endl;
    return 0;
}