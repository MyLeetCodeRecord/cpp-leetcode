/*
 * @lc app=leetcode.cn id=813 lang=cpp
 *
 * [813] 最大平均值和的分组
 */

// @lc code=start
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int K) {
        int n = nums.size();
        vector<double> prefixSum(n+1, 0);
        for(int i=1; i<=n; i++){
            prefixSum[i] = prefixSum[i-1]+nums[i-1];
        }
        // dp[i][k]: 将0~i划分为最多k个子数组的最大分数
        vector<vector<double>> dp(n+1, vector<double>(K+1, 0));
        for(int i=1; i<=n; i++){
            dp[i][1] = prefixSum[i] / i;  // 没有初始化会出错
            for(int k=2; k<=K; k++){
                for(int j=0; j<i; j++){
                    dp[i][k] = max(dp[i][k], dp[j][k-1] + (prefixSum[i]-prefixSum[j])/(i-j));
                }
            }
        }
        return dp[n][K];
    }
};
// @lc code=end

