int upperbound(vector<int>&arr,int n,int x){
    int s=0,e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]>=x){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return s;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int index=-1,count=0;
    for(int i=0;i<n;i++){
        int cnt=m-upperbound(matrix[i],m,1);
        if(cnt>count){
            count=cnt;
            index=i;
        }
    }
    return index;
}
