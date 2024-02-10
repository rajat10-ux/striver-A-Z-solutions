vector<int> rotateArray(vector<int>arr, int k) {
    // Write your code here.
    // k=k%arr.size();
    // reverse(arr.begin(),arr.begin()+k);
    // reverse(arr.begin()+k,arr.end());
    // reverse(arr.begin(),arr.end());
    // return arr;
  //TC O(arr.size())
  //SC O(1)
      int temp[k];
 int n=arr.size();
    for(int i=0;i<k;i++)
    {
        temp[i]=arr[i];
    }
    for(int i=k;i<n;i++)
    {
        arr[i-k]=arr[i];
    }
    for (int i=0;i<k;i++) {
        arr[n-k+i]=temp[i];
    }
    return arr;
}
//TC O(arr.size())
//SC O(K)

//
