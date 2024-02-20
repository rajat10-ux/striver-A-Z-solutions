vector<int> findPeakGrid(vector<vector<int>> &g){

    // Write your code here.    

    int n = g.size();

    int m = g[0].size();

    int ans1 = -1 , ans2 = -1;

    int max = g[0][0];

 

    for(int i=0; i<n; i++)

    {

        int low = 0, high = m-1;

        while(low <= high)

        {

            int mid = (low + high) / 2;

            if(g[i][mid] >= max)

            {

                max = g[i][mid];

                ans1 = i;

                ans2 = mid;

                low = mid + 1;

            }

            else

            {

                high = mid - 1;

            }

            

        }

    }

 

    return {ans1, ans2};

}
