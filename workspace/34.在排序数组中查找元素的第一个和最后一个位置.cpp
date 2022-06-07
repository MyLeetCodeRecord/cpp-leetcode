/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    // 二分的两种策略-找到左边界和右边界
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        bool exist = false;
        // 左边界
        while(left<=right){
            int mid = (right-left)/2 + left;
            if(nums[mid]>=target){
                right = mid-1;
                if(nums[mid]==target)
                    exist = true;
            }
            else
                left = mid+1;
        }
        int ans1 = exist ? left : -1;
        // 右边界
        left = 0;
        right = nums.size()-1;
        while(left<=right){
            int mid = (right-left)/2 + left;
            if(nums[mid]<=target)
                left = mid+1;
            else
                right = mid-1;
        }
        int ans2 = exist ? right : -1;
        return {ans1, ans2};
    }
};
// @lc code=end

