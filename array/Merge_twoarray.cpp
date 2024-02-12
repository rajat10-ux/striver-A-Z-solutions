#include<vector>

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, 
vector<long long> &b){
	long long int i=a.size()-1,j=0;
	while(i>=0 && j<b.size() && a[i]>b[j]){
		swap(a[i--],b[j++]);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
}

//TC O(A.SIZE()*B.SIZE())
