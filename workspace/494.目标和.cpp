/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int n: nums)
            sum += n;
        if(sum<target || (sum-target)%2!=0)
            return 0;
        // C-(sum-C) = target
        int C = (sum+target)/2;
        vector<int> dp(C+1, 0);
        dp[0] = 1;
        for(int i=0; i<nums.size(); i++){
            for(int j=C; j>=nums[i]; j--){
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[C];
    }
};
// @lc code=end

