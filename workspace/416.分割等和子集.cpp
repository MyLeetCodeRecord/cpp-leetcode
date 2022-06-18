/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    // 0-1背包
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int n: nums)
            sum += n;
        if(sum % 2 != 0)
            return false;
        int C = sum / 2;
        vector<int> dp(C+1, 0);
        // value[], weights[]都是nums[]
        for(int i=0; i<nums.size(); i++){
            for(int j=C; j>=nums[i]; j--){
                dp[j] = max(dp[j], dp[j-nums[i]]+nums[i]);
            }
        }
        return dp[C] == C;
    }
};
// @lc code=end

