#include<bits/stdc++.h>
using namespace std;
class Queue{
public:
int *arr;
int size;
int front;
int rear;
Queue(int size){
        arr=new int[size];
        this->size=size;
        front=-1;
        rear=-1;
}
void push(int data){
        if(rear=size-1){
                cout<<"queue full";
                return;
        }
        else if(front==-1 && rear==-1){
                front++;
                rear++;
                arr[rear]=data;
        }
        else{
                rear++;
                arr[rear]=data;
        }
}
void pop(){
        if(front==-1 && rear==-1){
                cout<<"unserflo";
                return;
        }
        else if(front==rear){
                arr[front]=-1;
                front=-1;
                rear=-1;
        }
        else{
                arr[front]=-1;
                front++;
        }
}
bool isEmpty(){
        if(front==-1 && rear==-1){
                return true;
        }
        else{
                return false;
        }
}
int getsize(){
        return rear-front+1;
}
int getfront(){
        if(front==-1){
                cout<<"no element";
                return -1;
        }
        else{
                return arr[front];
        }
}
};
int main(){
Queue q(5);
q.push(100);
q.push(105);
q.push(185);
q.push(85);
return 0;
}