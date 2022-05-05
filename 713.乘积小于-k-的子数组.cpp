/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于 K 的子数组
 */

// @lc code=start
class Solution {
public:
    // 子数组是连续的, 并且每个值为整数, 因此还是可以用滑动窗口
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int product = 1;
        int ans = 0;
        while(right<nums.size()){
            // 无脑右移
            product *= nums[right++];
            // 收缩左边界(严格小于 k)
            while(left<right && product>=k){
                product /= nums[left++];
            }
            ans += (right-left);    // 只要固定right, 任选left即可得到所有子数组
        }
        return ans;
    }
};
// @lc code=end

