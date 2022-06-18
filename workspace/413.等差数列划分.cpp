/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

// @lc code=start
class Solution {
public:
    // 子数组 => 连续
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        // dp[i]是严格以nums[i]结尾的最长等差数列长度
        // 而对等差数列计数则需要固定结尾元素为nums[i], 遍历开始位置并控制长度>=3, 即ans+=(dp[i]-3+1)
        vector<int> dp(nums.size(), 2);
        dp[0] = 1;
        for(int i=2; i<nums.size(); i++){
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2]){
                dp[i] = dp[i-1]+1;
                ans += dp[i]-3+1;
            }
            else{
                dp[i] = 2;
            }
        }
        return ans;
    }
};
// @lc code=end

