#include<iostream>
#include<stack>

using namespace std;

class Stack{

    public:
       int *arr;
       int top;
       int size;
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;

    }
    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }

    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack underflow";
        }

    }
    int peek(){
        if(top>=0){
            return arr[top];

        }
        else{
            cout<<"Stack is empty";
             return -1;
        }

    }
    bool isEmpty(){
        if(top<0) return true;
        else return false;

    }

};

int main(){

    Stack st(5);
    st.push(22);
    st.push(23);
    st.push(24);
    st.push(12);
    st.push(34);

    cout<<st.peek()<<" top of stack element \n"; 
    st.pop();

    cout<<st.isEmpty();
    cout<<st.peek()<<" top of stack element after one pop \n";

    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();


}