/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = (nums[0]==1);
        int ans = dp[0];
        for(int i=1; i<nums.size(); i++){
            dp[i] = (nums[i]==1) ? dp[i-1]+1 : 0;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end

