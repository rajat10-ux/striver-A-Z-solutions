#include<bits/stdc++.h>
using namespace std;
class circ{
        public:
 int size;
 int *arr;
 int front;
 int rear;
 circ(int n){
        arr=new int[n];
        size=n;
        front=-1;
        rear=-1;
 }
 void push(int val){
        //overflow
        //single elememnt
        //normal//circular
        if((front==0 && rear==size-1) &&(rear==front-1)){
                cout<<"overflow";
        }
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
        for(int i=0;i<size;i++){
                cout<<arr[i]<<" ";
        }
        cout<<endl;
 }
};
int main(){
circ qu(5);
qu.print();
qu.push(100);
qu.print();
qu.push(10);
qu.print();
return 0;
}