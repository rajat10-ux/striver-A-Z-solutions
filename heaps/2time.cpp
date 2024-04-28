#include<bits/stdc++.h>
using namespace std;
class Heap{
public:
int *arr;
int size;
int capacity;
Heap(int capacity){
       arr=new int[capacity];
       this->capacity=capacity;
        this->size=0;
}
void insert(int val){
        if(size==capacity){
                cout<<"no heap";
                return;
        }
        size++;
        int i=size;
        arr[i]=val;
        while(i>1){
                int parent=i/2;
                if(arr[i]>arr[parent]){
                        swap(arr[i],arr[parent]);
                        i=parent;
                }
                else{
                        break;
                }
        }
}
void printheap(){
        for(int i=1;i<=size;i++){
             cout<<arr[i]<<" ";
        }
}
int deletenum(){
        int answer=arr[1];
        arr[1]=arr[size];
        size--;
        int index=1;
        while(index<size){
                int leftindex=2*index;
                int rightindex=2*index+1;
                int largestindex=index;
                if(leftindex<=size && arr[largestindex]<arr[leftindex]){
                        largestindex=leftindex;
                }
                if(rightindex<=size && arr[largestindex]<arr[rightindex]){
                        largestindex=rightindex;
                }
                if(index==largestindex) break;
                else swap(arr[index],arr[largestindex]);
        }
        return answer;
}
};
void heapify(int*arr,int n,int index){
        int leftindex=2*index;
        int rightindex=2*index+1;
        int largestindex=index;
        if(leftindex<=n && arr[largestindex]<arr[leftindex]){
                largestindex=leftindex;
        }
        if(rightindex<=n && arr[largestindex]<arr[rightindex]){
                largestindex=rightindex;
        }
        if(largestindex!=index){
                swap(arr[index],arr[largestindex]);
                index=largestindex;
                heapify(arr,n,index);
        }
}
void buildheap(int*arr,int n){
        for (int  i = n/2; i >0; i--)
        {
                heapify(arr,n,i);
        }
}
void heapsort(int*arr,int n){
        //tc O(NlogN)
        while (n!=1)
        {
                swap(arr[1],arr[n]);
                n--;
                heapify(arr,n,1);
        }      
}
int main(){
        int arr[7]={-1,5,10,15,20,25,12};
        buildheap(arr,7);
        for (int i = 0; i < 7; i++)
        {
                cout<<arr[i]<<" ";
        }
        heapsort(arr,6);
        cout<<endl<<"sort"<<endl;
            for (int i =1; i <=7; i++){
                cout<<arr[i]<<" ";
        }
return 0;
}