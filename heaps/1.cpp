#include<bits/stdc++.h>
using namespace std;
class heap{
        public:
int *arr;
int capacity;
int size;
heap(int capacity){
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
int i=size;
int deleete(){
        int answer=arr[i];
        arr[1]=arr[size];
        //last element ko dleeter karke original position 
        size--;
        int index=1;
        while (index<size){
                int leftindex=2*index;
                int rightindex=2*index+1;
                int largestindex=index;
if(leftindex<=size &&arr[largestindex]<arr[leftindex]){
                        largestindex=leftindex;
}
if(rightindex<=size &&arr[largestindex]<arr[rightindex]){
                        largestindex=rightindex;
        }
if(index==largestindex){
        break;
}
else{
        swap(arr[index],arr[largestindex]);
        index=largestindex;
}
return answer;
        } 
}
void printheap(){
        for(int i=1;i<=size;i++){
             cout<<arr[i]<<" ";
        }
}
};
void heapify(int*arr,int n,int index){
        int leftind=2*index;
        int rightind=2*index+1;
        int largest=index;
        if(leftind<=n && arr[leftind]>arr[largest]){
                largest=leftind;
        }
        if(leftind<=n && arr[rightind]>arr[largest]){
                largest=rightind;
        }
        if(index!=largest){
                swap(arr[index],arr[largest]);
                index=largest;
                heapify(arr,n,index);
        }
}
void buildheap(int *arr,int n){
        // n/2 to n se leaf node pehle se heap hota hai
        for(int i=n/2;i>0;i--){
                heapify(arr,n,i);
        }
}
void heapsort(int*arr,int n){
        while(n!=1){
                swap(arr[1],arr[n]);
                n--;
                heapify(arr,n,1);
        }
}
int main(){
int arr[]={-1,5,10,12,15,100};
int n=6;
buildheap(arr,6);
cout<<endl<<"print hepa"<<endl;
for(int i=1;i<=6;i++){
  cout<<arr[i]<<" ";
}
cout<<endl;
heapsort(arr,n);
cout<<endl<<"sort"<<endl;
for ( int i =1 ; i <=6; i++)
{
        cout<<arr[i]<<" ";
}
return 0;
}