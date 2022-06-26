/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MIN);
        dp[0] = nums[0];
        int ans = dp[0];
        for(int i=1; i<nums.size(); i++){
            dp[i] = (dp[i-1]>0) ? dp[i-1]+nums[i] : nums[i];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end

