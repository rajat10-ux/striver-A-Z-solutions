#include<bits/stdc++.h>
using namespace std;
class heap{
        public:
        int arr[100];
        int size=0;
        heap(){
                size=0;
                arr[0]=-1;
        }
        void insert(int val){
                size=size+1;
                int index=size;
                arr[index]=val;
                while (index>1)
                {
                        int parent=index/2;
                        if(arr[parent]<arr[index]){
                                swap(arr[parent],arr[index]);
                                index=parent;
                        }
                        else{
                                return;
                        }
                }
        }
        void print(){
                for ( int i = 1; i <=size; i++)
                {
                cout<<arr[i]<<" ";
                }cout<<endl;
        }
        void deletefromheap(){
                if(size==0){
                        cout<<"nothing to deleyte";
                        return;
                }
                // root wale node ko first mai lekar aayo
                arr[1]=arr[size];
                //delete kafro
                size--;
                int i=1;
                while (i<1)
                {
                        int leftind=2*i;
                        int rightind=2*i+1;
       if(leftind<size && arr[i]<arr[leftind]){
                                swap(arr[i],arr[leftind]);
                        }
                        else if(rightind<size && arr[i]<arr[rightind]){
                                swap(arr[i],arr[rightind]);
                        }
                        else {
                                return;
                        }
                }
        }
};
void heapify(int *arr,int n,int i){
  int large=i;
  int left=2*i;
  int right=2*i+1;
  if(left<=n && arr[large]<arr[left]){
        large=left;
  }
  if(right<=n && arr[large]<arr[right]){
        large=right;
  }
  if(large!=i){
        swap(arr[large],arr[i]);
        heapify(arr,n,large);
  }
}
void heapsort(int*arr,int n){
        int size=n;
        while (size>1)
        {
                swap(arr[size],arr[1]);
                heapify(arr,size,1);
        }
}
int main(){
heap h;
// h.insert(50);
// h.insert(55);
// h.insert(53);
// h.insert(52);
// h.insert(54);
// h.print();
// cout<<endl;
// h.deletefromheap();
// cout<<endl<<"after deletre"<<endl; 
// h.print();
int arr[6]={-1,54,53,55,52,50};
int n=5;
for (int  i = n/2; i>0; i--)
{
        heapify(arr,n,i);
}
cout<<"print moe"<<endl;
for (int  i = 1; i <=n; i++)
{
        cout<<arr[i]<<" ";
}
heapsort(arr,8);
cout<<"sort"<<endl;
for (int  i = 1; i <=n; i++)
{
        cout<<arr[i]<<" ";
}
return 0;
}