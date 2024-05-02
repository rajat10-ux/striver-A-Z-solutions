#include<bits/stdc++.h>
using namespace std;
class Kqueue{
public:
int n,k,freespot;
int*arr,*front,*rear,*next;
Kqueue(int _n,int _k):n(_n),k(_k),freespot(0){
        arr=new int[n];
        next=new int[n];
        front=new int[k];
        rear=new int[k];
        for (int  i = 0; i < k; i++)
        front[i]=rear[i]=-1;
        for (int  i = 0; i < n; i++)
        next[i]=i+1;
        next[n-1]=-1;
}
bool push(int x,int qi){
        // overflow
        if(freespot==-1){
                return false;
        }
        // find index frree spot
        int index=freespot;
        // update freespot
        freespot=next[index];
        if(front[qi]==-1){
                front[qi]=index;
        }
        else{
                // link new elemenet to tjat qs
                next[rear[qi]]=index;
        }
        next[index]=-1;
        rear[qi]=index;
        arr[index]=x;
        return true;
}
int pop(int qi){
if(front[qi]==-1){
        return -1;
}
// find index to top
int index=front[qi];
//front update
front[qi]=next[index];
//update freespots
next[index]=freespot;
freespot=index;
return arr[index];
}
~Kqueue(){
        delete[]arr;
         delete[]front;
          delete[]rear;
           delete[]next;
}
};
int main(){
Kqueue kq(8,3);
cout<<kq.push(1,0)<<endl;
cout<<kq.push(2,0)<<endl;
cout<<kq.push(5,1)<<endl;
cout<<kq.push(3,0)<<endl;
cout<<kq.pop(1)<<endl;
return 0;
}