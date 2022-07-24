/*
 * @lc app=leetcode.cn id=813 lang=cpp
 *
 * [813] 最大平均值和的分组
 */

// @lc code=start
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int K) {
        int N = nums.size();
        // 累计和 => 用于求区间和(平均值)
        vector<double> cumSum(N+1, 0.0);
        for(int i=1; i<=N; i++){
            cumSum[i] = cumSum[i-1] + nums[i-1];
        }
        // 区间dp[i][k]
        vector<vector<double> > dp(N+1, vector<double>(K+1, 0));
        dp[0][0] = 0;
        for(int i=1; i<=N; i++){
            dp[i][1] = cumSum[i] / i;
            for(int k=2; k<=min(K, i); k++){
                for(int j=k-1; j<i; j++){
                    dp[i][k] = max(dp[i][k], dp[j][k-1]+(cumSum[i]-cumSum[j])/(i-j));
                }
            }
        }
        double ans = 0.0;
        for(int k=1; k<=K; k++){
            ans = max(ans, dp[N][k]);
        }
        return ans;
    }
};
// @lc code=end

