#include<bits/stdc++.h>
using namespace std;
int slidemaxmin(vector<int>&arr,int k){
        deque<int>dq1,dq2;
        int sum=0;
        for (int  i = 0; i < k; i++)
        {
         while(!dq1.empty() && arr[i]>=arr[dq1.back()]){
                        dq1.pop_back();
            }
          while(!dq2.empty() && arr[i]<=arr[dq2.back()]){
                        dq2.pop_back();
         }
         dq1.push_back(i);
         dq2.push_back(i);
        }
        sum+=arr[dq1.front()]+arr[dq2.front()];
        for (int  i = k; i < arr.size(); i++)
        {
                if(!dq1.empty() && i-dq1.front()>=k){
                        dq1.pop_front();
                }
                if(!dq2.empty() && i-dq2.front()>=k){
                        dq2.pop_front();
                }
         while(!dq1.empty() && arr[i]>=arr[dq1.back()]){
                        dq1.pop_back();
            }
          while(!dq2.empty() && arr[i]<=arr[dq2.back()]){
                        dq2.pop_back();
         }
             dq1.push_back(i);
         dq2.push_back(i);
          sum+=arr[dq1.front()]+arr[dq2.front()];
        }
        return sum;
}
int main(){
vector<int>arr={2,5,-1,7,-3,-1,-2};
cout<<slidemaxmin(arr,5);
return 0;
}