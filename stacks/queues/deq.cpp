#include<bits/stdc++.h>
using namespace std;
class Deque{
public:
int*arr;
int size;
int front;
int rear;
Deque(int size){
        arr=new int[size];
        this->size=size;
        front=-1;
        rear=-1;
}
void pushback(int val){
//overflow
//empty case
//normal
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
void pushfront(int val){
        if((front==0 && rear==size-1) || (rear==front-1)){
                cout<<"overflow";
        }
        else if(front==-1 && rear==-1){
                front++;
                rear++;
                arr[front]=val;
        }
        else if(front==0 && rear!=size-1){
                front=size-1;
                arr[front]=val;
        }
        else{
                front--;
                arr[front]=val;
        }
}
void popback(){
if(front==-1 && rear==-1){
        cout<<"underflow";
}
else if(front==rear){
        arr[rear]=-1;
        front=-1;
        rear=-1;
}
else if(rear==0){
arr[rear]=-1;
rear=size-1;
}
else{
        arr[rear]=-1;
        rear--;
}
}
void popfront(){
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
};
int main(){

return 0;
}