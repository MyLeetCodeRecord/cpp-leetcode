/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    // LIS: 不要求连续; 严格递增
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1;
        // dp[i]: 严格以nums[j]结尾的LIS长度
        vector<int> dp(nums.size(), 1);
        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end

