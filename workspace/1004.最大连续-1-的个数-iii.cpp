/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
class Solution {
public:
    // 保持窗口内最多有k个0, 问这样的数组最长长度是多少?
    // 滑动窗口
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int l = 0, r = 0;
        int zeroCnt = 0;
        while(r < n){
            zeroCnt += (nums[r++]==0);
            while(zeroCnt > k){
                zeroCnt -= (nums[l++]==0);
            }
            ans = max(ans, r-l);
        }
        return ans;
    }
};
// @lc code=end

