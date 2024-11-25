// two stack in a array
#include<iostream>

using namespace std;

class TwoStack{
    public: 
       int * arr;
       int top1;
       int top2;
       int size;


       TwoStack(int size){
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;

       }
       void push1(int element){
        //atleast one empty space is present
        if(top2-top1>1){
            top1++;
            arr[top1] = element;
        }
        else{
            cout<<"stack overflow";
        }

       }
       void push2(int element){
        if(top2-top1>1){
            top2--;
            arr[top2] = element;
        }
        else cout<<"stack overflow";

       }
       int pop1(){
        if(top1>=0){
            int ans = arr[top1];
        }
        else return -1;

       }
       int pop2(){
        if(top2<size){
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else return -1;

       }

};