class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        // 由于dp的更新每次只使用第i-1行, 不会有覆盖问题, 所以事实上可以直接用cost数组作为dp
        vector<vector<int>> dp = costs;
        for(int i=1; i<costs.size(); i++){
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costs[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + costs[i][2];
        }
        return min(dp.back()[0], min(dp.back()[1], dp.back()[2]));
    }
};