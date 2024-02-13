#include<vector>

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
// 	sort(arr.begin(),arr.end());
// vector<vector<int>>ans;
// for(int i=0;i<arr.size();i++){
// 	int start=arr[i][0];
// 	int end=arr[i][1];
// 	if(!ans.empty() &&end<=ans.back()[1]){
// 		continue;
// 	}
// 	for(int j=i+1;j<arr.size();j++){
// 		if(end>=arr[j][0]){
// 			end=max(end,arr[j][1]);
// 		}
// 	}
// 	ans.push_back({start,end});
// }
// return ans;
//TC O(NLOGN)+O(2*N) 
//SC O(N)
sort(arr.begin(),arr.end());
 vector<vector<int>>ans;
for(int i=0;i<arr.size();i++){
  if(ans.empty() || arr[i][0]>ans.back()[1]){
	  ans.push_back(arr[i]);
  }
  ans.back()[1]=max(ans.back()[1],arr[i][1]);
}
return ans;
}

