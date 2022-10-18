/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
class Solution {
public:
    // 保持窗口内最多有k个0, 问这样的数组最长长度是多少?
    int longestOnes(vector<int>& nums, int k) {
        int ans = min(k, (int)nums.size());
        int left = 0;
        int right = 0;
        int zeroNum = 0;
        while(right < nums.size()){
            // 扩大右边界
            zeroNum += (nums[right++]==0);
            // 收缩左边界
            while(zeroNum > k){
                zeroNum -= (nums[left++]==0);
            }
            ans = max(ans, right-left);
        }
        return ans;
    }
};
// @lc code=end

