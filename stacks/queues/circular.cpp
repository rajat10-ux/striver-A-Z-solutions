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
        this->size=size;
        front=-1;
        rear=-1;
}
void push(int val){
        //overflow
        if((front==0 && rear==size-1) || (rear==front-1)){
                cout<<"overflow";
        }
        //not startred
        else if(front==-1 && rear==-1){
                front++;
                rear++;
                arr[rear]=val;
        }
        else if(rear==size-1 && front!=0){
                rear=0;
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
        }
        else if(front==rear){
                arr[front]=-1;
                front=-1;
                rear=-1;   
        }
        else if(front==size-1){
                arr[front]=-1;
                front=0;
        }
        else{
                arr[front]=-1;
                front++;
        }
}
void print(){
        for (int i = 0; i < size; i++)
        {
                cout<<arr[i]<<" ";
        }
}
};
int main(){
Queue q(5);
q.push(10);
q.push(15);
q.pop();
q.pop();
q.push(15);
q.push(15);
q.push(15);
q.push(100);
q.print();
return 0;
}