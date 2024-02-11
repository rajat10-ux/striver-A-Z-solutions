#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
//    //   Write your code here
// 	int count_0=0;
// 	int count_1=0;
// 	int count_2=0;
// 	for( int i=0;i<n;i++){
// 		if(arr[i]==0)
// 		{
// 			count_0++;
// 		}
// 		else if(arr[i]==1)
// 		{
// 			count_1++;
// 		}
// 		else if(arr[i]==2)
// 		{
// 			count_2++;
// 		}
// 	}
// 	int k=0;
// 	for(int i=0;i<count_0;i++)
// 	{
// 		arr[k]=0;
// 		k++;
// 	}
// 	for(int i=0;i<count_1;i++)
// 	{
// 		arr[k]=1;
// 		k++;
// 	}
// 	for(int i=0;i<count_2;i++)
// 	{
// 		arr[k]=2;
// 		k++;
// 	}
  //Dutch national flag alogrithm
int low=0,mid=0,high=n-1;
while(mid<=high){
	if(arr[mid]==0){
		swap(arr[low],arr[mid]);
		low++;
		mid++;
	}
	else if(arr[mid]==1){
		mid++;
	}
	else if(arr[mid]==2){
       swap(arr[mid],arr[high]);
	   high--;
	}
}
}
//TC O(N)
