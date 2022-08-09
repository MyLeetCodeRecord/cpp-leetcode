/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(l < r){
            int mid = (l + r)/2;
            if(nums[mid] < target)
                l = mid+1;
            else
                r = mid;
        }
        return (l<nums.size() && nums[l]==target) ? l : -1;
    }
};
// @lc code=end

