/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    // 传递dp
    int maxSubArray(vector<int>& nums) {
        // dp[i]: 严格以nums[i]结尾的最大子数组和
        vector<int> dp(nums.size(), INT_MIN);
        dp[0] = nums[0];
        int ans = dp[0];
        for(int i=1; i<nums.size(); i++){
            dp[i] = (dp[i-1]>0) ? dp[i-1]+nums[i] : nums[i];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    // 前缀和 + minLeft
    // int maxSubArray(vector<int>& nums) {
    //     int n = nums.size();
    //     int ans = INT_MIN;
    //     vector<int> pre(n+1, 0);
    //     int leftMin = 0;
    //     for(int i=1; i<=n; i++){
    //         pre[i] = pre[i-1] + nums[i-1];
    //         ans = max(ans, pre[i] - leftMin);
    //         leftMin = min(leftMin, pre[i]);
    //     }
    //     return ans;
    // }
};
// @lc code=end

