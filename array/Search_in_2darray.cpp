   bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0,j=m-1;
      // if j>0 consider par j 00 tak nahi jatra hai isliye always j ko>-1
        while(i<n && j>-1){
            int sum=matrix[i][j];
            if(sum==target){
                return true;
            }
            else if(sum<target){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
//TC O(N+M) SC O(1)
