/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于 K 的子数组
 */

// @lc code=start
class Solution {
public:
    // 子数组是连续的, 并且每个值为正数, 因此还是可以用滑动窗口
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long product = 1;
        int l = 0, r = 0;
        int cnt = 0;
        while(r < nums.size()){
            product *= nums[r++];
            while(l<r && product>=k){
                product /= nums[l++];
            }
            cnt += r-l;     // 固定right, 枚举left
        }
        return cnt;
    }
};
// @lc code=end

