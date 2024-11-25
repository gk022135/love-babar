//reverse string using stack


#include<iostream>
using namespace std;

class Stack{
    public:
     int size;
     char *arr;
     int top;
    Stack(char element){
        this->size = size;
        arr = new char[size];
        top = -1;
    }
    void push(char v){
        if(size-top>1){
            top++;
            arr[top] = v;
        }
        else cout<<"stack overflow";
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else cout<<"stack underflow";
    }

};