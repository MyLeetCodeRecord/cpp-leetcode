class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> cntY(n+1, 0);
        for(int i=1; i<=n; i++){
            cntY[i] = cntY[i-1] + (customers[i-1]=='Y');
        }
        int minCost = n;
        int ans = 0;
        for(int i=0; i<=n; i++){
            int cost = (i-cntY[i]) + (cntY.back()-cntY[i]);
            if(cost < minCost){
                minCost = cost;
                ans = i;
            }
        }
        return ans;
    }
};