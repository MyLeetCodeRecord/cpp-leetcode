/*
 * @lc app=leetcode.cn id=1800 lang=cpp
 *
 * [1800] 最大升序子数组和
 */

// @lc code=start
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0;
        int sum = 0;
        int i = 0;
        // 不需要用动态规划, 每个求和子数组是单调递增的, 破坏递增后重置sum
        for(int i=0; i<nums.size(); i++){
            if(i==0 || nums[i]>nums[i-1])
                sum += nums[i];
            else
                sum = nums[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};
// @lc code=end

