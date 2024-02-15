int finmin(vector<int>&arr){
    int n=arr.size();
    int s=0,e=n-1;
    int mid=s+(e-s)/2;
    while(s<e){
        if(arr[mid]>=arr[e]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}
int findKRotation(vector<int> &arr){
 int ans=finmin(arr);
 return ans;
}
//key pint is return index of find minimum in array
