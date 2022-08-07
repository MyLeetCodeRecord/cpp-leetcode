/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    // acwing - 二分法模板
    int binary_search_left(vector<int> q, int l, int r, int target){
        while(l<r){
            int mid = (l+r)/2;
            if(q[mid] < target)
                l = mid+1;
            else
                r = mid;
        }
        return l;
    }
    int binary_search_right(vector<int> q, int l, int r, int target){
        while(l<r){
            int mid = (l+r+1)/2;
            if(q[mid] > target)
                r = mid-1;
            else
                l = mid;
        }
        return r;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftEnd = binary_search_left(nums, 0, nums.size()-1, target);
        if(leftEnd >= nums.size() ||nums[leftEnd] != target)
            return {-1, -1};
        int rightEnd = binary_search_right(nums, 0, nums.size()-1, target);
        return {leftEnd, rightEnd};
    }
};
// @lc code=end

