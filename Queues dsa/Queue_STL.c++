#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<int> q;

    q.push(10);
    q.push(11);
    q.push(24);

    cout<<"size of  queue"<<q.size()<<"\n";

    q.pop();

    cout<<"Front of queue:" <<q.front()<<"\n";
}