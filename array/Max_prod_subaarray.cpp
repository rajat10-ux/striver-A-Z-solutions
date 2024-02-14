#include<bits/stdc++.h>
int subarrayWithMaxProduct(vector<int> &arr){
  int prefix=1,suffix=1;
  int maxi=INT_MIN;
  for(int i=0;i<arr.size();i++){
	  if(prefix==0) prefix=1;
	  if(suffix==0) suffix=1;
	  prefix=prefix*arr[i];
	  suffix=suffix*arr[arr.size()-i-1];
	  maxi=max(maxi,max(prefix,suffix));
  }
  return maxi;
}
//TC O(N)
