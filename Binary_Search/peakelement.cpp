int findmax(vector<vector<int>> &arr,int n,int m,int col){
    int index=-1;
    int maxi=-1;
    for(int i=0;i<n;i++){
        if(arr[i][col]>maxi){
            maxi=arr[i][col];
            index=i;
        }
    }
    return index;
}
vector<int> findPeakGrid(vector<vector<int>> &arr){
      int n=arr.size();
      int m=arr[0].size();
      int low=0,high=m-1;
      while(low<=high){
          int mid=(low+high)/2;
          int maxrow=findmax(arr,n,m,mid);
          int left=mid-1>=0?arr[maxrow][mid-1]:-1;
          int right=mid+1<m?arr[maxrow][mid+1]:-1;
          if(arr[maxrow][mid]>left && arr[maxrow][mid]>right){
              return {maxrow,mid};
          }
          else if(arr[maxrow][mid]<left){
              high=mid-1;
          }
          else{
              low=mid+1;
          }
      }
      return {-1,-1};
}
