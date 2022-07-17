/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob198(vector<int>& nums, int start, int end) {
        if(end-start==1)
            return nums[start];
        vector<int> dp(end-start, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start+1]);
        for(int i=2; i<end-start; i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[start+i]);
        }
        return dp.back();
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        return max(rob198(nums, 0, nums.size()-1), rob198(nums, 1, nums.size()));
    }
};
// @lc code=end

