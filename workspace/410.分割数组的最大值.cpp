/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int K) {
        int N = nums.size();
        // 累计和
        vector<int> cumSum(N+1, 0);
        for(int i=1; i<=N; i++){
            cumSum[i] = cumSum[i-1] + nums[i-1];
        }
        // 区间dp[i][k]
        vector<vector<int> > dp(N+1, vector<int>(K+1, INT_MAX));
        for(int i=1; i<=N; i++){
            dp[i][1] = cumSum[i];
            for(int k=2; k<=min(K, i); k++){
                for(int j=k-1; j<i; j++){
                    int curMaxSum = max(dp[j][k-1], cumSum[i]-cumSum[j]);
                    dp[i][k] = min(dp[i][k], curMaxSum);
                }
            }
        }
        return dp[N][K];
    }
};
// @lc code=end

