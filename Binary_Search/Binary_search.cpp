int binarySearch(int *input, int n, int val)
{
	int s=0,e=n-1;
	int mid=s+(e-s)/2;
	while(s<=e)
	{
		if(input[mid]==val){
		return mid;
		}
		else if(input[mid]<val)
		{
			s=mid+1;
		}
		else if(input[mid]>val)
		{
			e=mid-1;
		}
		mid=s+(e-s)/2;
	}
	return -1;
}
//TC O(NLOGN)
