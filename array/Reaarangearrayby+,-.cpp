vector<int> alternateNumbers(vector<int>&arr) {
    // Write your code here.
    int i,n=arr.size();
    vector<int>ans(n,0);
   int pos=0,neg=1;
   for(i=0;i<n;i++){
       if(arr[i]<0){
           ans[neg]=arr[i];
           neg+=2;
       }
       else{
             ans[pos]=arr[i];
           pos+=2;
       }
   }
   return ans;
}
// TC O(N) SC O(N)
