/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int ans = k;
        while(right < nums.size()){
            // 扩大右边界, right位置为0时k--
            k -= (nums[right++]==0);
            // 收缩左边界, 直到k非负
            while(k < 0){
                if(nums[left]==0)
                    k++;
                left++;
            }
            // 此时k=0
            ans = max(ans, right-left);
        }
        return ans;
    }
};
// @lc code=end

