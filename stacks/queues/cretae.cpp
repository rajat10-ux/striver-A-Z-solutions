#include<bits/stdc++.h>
using namespace std;
class Queue{
public:
int*arr;
int size;
int front;
int rear; 
Queue(int size){
        arr=new int[size];
        front=-1;
        rear=-1;
        this->size=size;
}
void push(int val){
        // check full
        if(rear==size-1){
                cout<<"overflow"<<endl;
                return;
        }
        // ye h agar first element insert karna hai tab
        else if(front==-1 && rear==-1){
                front++;
                rear++;
                arr[rear]=val;
        }
        else{
                rear++;
                arr[rear]=val;
        }
}
void pop(){
 if(front==-1 && rear==-1){
        cout<<"underflow";
        return;
 }
 else if(front==rear-1){
        arr[front]=-1;
        front=-1;
        rear=-1;
 }
 else{
        arr[front]=-1;
        front++;
 }
}
bool isempty(){
        if(front==-1 && rear==-1){
                return true;
        }
        return false;
}
int  getsize(){
        if(front==-1 && rear==-1){
                return 0;
        }
        return rear-front+1;
}
int getfront(){
        if(front==-1){
                cout<<"no element";
        }
                return arr[front];
}
void print(){
        for (int  i = 0; i < size; i++)
        {
                cout<<arr[i]<<" ";
        }
        cout<<endl;
}
};
int main(){
Queue q(5);
q.push(10);
q.push(15);
q.push(16);
q.push(18);
q.pop();
cout<<endl;
cout<<q.getsize();
q.print();
return 0;
}