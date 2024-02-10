vector<int> moveZeros(int n, vector<int> arr) {
    // Write your code here.
  int i=0,j;
  for(j=0;j<n;j++){
      if(arr[j]!=0){
          swap(arr[j],arr[i]);
          i++;
      }
  }
  return arr;
}
//TC O(N)
//SC O(1)
