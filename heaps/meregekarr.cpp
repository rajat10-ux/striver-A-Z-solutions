#include<bits/stdc++.h>
using namespace std;
    class Info{
      public:
      int data;
      int colindex;
      int rowindex;
      Info(int a,int b,int c){
          this->data=a;
          this->colindex=b;
          this->rowindex=c;
      }
    };
    class compare{
      public:
      bool operator()(Info*a,Info*b){
          return a->data > b->data;
      }
    };
  vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        vector<int>ans;
        priority_queue<Info*,vector<Info*>,compare>pq;
        for(int i=0;i<k;i++){
            int element=arr[i][0];
            Info*temp=new Info(element,i,0);
            pq.push(temp);
        }
        while(!pq.empty()){
            Info*newelement=pq.top();
            pq.pop();
            ans.push_back(newelement->data);
            int i=newelement->colindex;
            int j=newelement->rowindex;
            if(j+1<arr[i].size()){
                Info*newtemp=new Info(arr[i][j+1],i,j+1);
                pq.push(newtemp);
            }
        }
        return ans;
}
int main(){
    vector<vector<int>>arr={
       {1,4,8,11},
        {2,3,6,10},
        {5,7,12,11}
};
int n=4,k=3;
vector<int>ans=mergeKArrays(arr,3);
for (int i = 0; i < ans.size()-1; i++)
{
        cout<<ans[i]<<" ";
}
return 0;
}