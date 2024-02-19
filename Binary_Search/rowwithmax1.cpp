int lowerindex(vector<int> &arr,int n,int x){

 int low=0;

 int high=n-1;

 int ans=n;

 while(low<=high){

     int mid=(low+high)/2;

     if(arr[mid]>=x){

         high=mid-1;

         ans=mid;

     }

     else{

         low=mid+1;

     }

 }

 return ans;

}

 

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {

    int result=-1;

 

    int rowIndex=-1;

    for (int i = 0; i < n; i++) {

        int countOnes= m- lowerindex(matrix[i],m,1);

        if(countOnes >result){

            result=countOnes;

            rowIndex=i;

        }

    }

    return rowIndex;

 

}
