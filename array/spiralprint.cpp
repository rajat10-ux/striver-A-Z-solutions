vector<int> spiralMatrix(vector<vector<int>>&arr) {
    // Write your code here.
    vector<int>ans;
    int n=arr.size();
    int m=arr[0].size();
    int left=0,top=0,right=m-1,bottom=n-1;
    while(left<=right && top<=bottom){
        for(int i=left;i<=right;i++){
            ans.push_back(arr[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(arr[i][right]);
        }
        right--;
        if(top<=bottom){
        for(int i=right;i>=left;i--){
            ans.push_back(arr[bottom][i]);
        }
        bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(arr[i][left]);
            }
            left++;
        }
    }
    return ans;
}
//TC O(M+N) SC O(N)
