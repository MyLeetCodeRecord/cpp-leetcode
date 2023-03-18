/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    // 二分法 - 折叠数组
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l < r){
            // 去重
            while(l+1 < r && nums[l]==nums[l+1])
                l++;
            while(l < r-1 && nums[r]==nums[r-1])
                r--;
            int mid = (l+r)/2;
            if(nums[mid] > nums[r])
                l = mid+1;
            else
                r = mid;
        }
        return nums[l];
    }
};
// @lc code=end

