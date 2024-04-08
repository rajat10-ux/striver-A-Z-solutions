 int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int start=0;
        int balance=0,defi=0;
        for(int i=0;i<gas.size();i++){
            balance+=gas[i]-cost[i];
            if(balance<0){
                defi+=abs(balance);
                start=i+1;
                balance=0;
            }
        }
        if(balance-defi>=0){
            return start;
        }
        return -1;
    }
