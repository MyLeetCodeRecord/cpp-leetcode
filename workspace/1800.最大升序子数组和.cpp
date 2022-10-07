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
        while(i<nums.size()){
            if(i==0 || nums[i]>nums[i-1])
                sum += nums[i];
            else
                sum = nums[i];
            i++;
            ans = max(ans, sum);
        }
        return ans;
    }
};
// @lc code=end

