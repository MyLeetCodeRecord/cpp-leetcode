/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    // 二分法 - 折叠数组(无重复)
    // 目标 => 找到折叠位置
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l < r){
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

