/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while(l < r){
            int mid = (l + r) / 2;
            // mid和mid^1来实现「成对比较」
            // - mid是奇数 => mid^1 = mid-1
            // - mid是偶数 => mid^1 = mid+1
            if(nums[mid]==nums[mid^1])
                l = mid+1;
            else
                r = mid;
        }
        return nums[l];
    }
};
// @lc code=end

