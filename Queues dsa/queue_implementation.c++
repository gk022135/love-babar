#include<iostream>
using namespace std;

class queueImp{
    public:
      int front;
      int rear;
      int *arr;
      int size;
    queueImp(int size){
        this->size = size;
        front = 0;
        rear = 0;
        arr = new int[size];
    }
    void push(int ele){
        if(rear == size){
            cout<<"queue is full"<<"\n";
        }
        else{
            arr[rear] = ele;
            rear++;

        }

    }
    int pop(){
        if(front == rear){
            return -1;
        }
        else{
            int ans = arr[front];
            arr[front] = -1;
            if(rear == front){
                front = 0;
                rear = 0;
            }
            return ans;
        }

    }
    bool empty(){
        if(rear == front) return true;
        else return false;

    }
    int qfront(){
        if(front == rear) return -1;
        else return arr[front];

    }

};