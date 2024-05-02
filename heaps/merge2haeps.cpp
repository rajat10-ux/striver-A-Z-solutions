   void heapify(vector<int>&arr,int n ,int i){
        int left=2*i+1;
        int right=2*i+2;
        int largest=i;
        if(left<n && arr[left]>arr[largest]){
            largest=left;
        }
        if(right<n && arr[right]>arr[largest]){
            largest=right;
        }
        if(i!=largest){
            swap(arr[i],arr[largest]);
            heapify(arr,n,largest);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
         for(int i=0;i<m ;i++) a.push_back(b[i]);
          for(int i=(a.size()/2)-1;i>=0;i--){
              heapify(a,a.size(),i);
          }
        return a;
    }
