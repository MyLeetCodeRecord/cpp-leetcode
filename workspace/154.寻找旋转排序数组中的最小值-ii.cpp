/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    // 二分法 - 折叠数组(无重复)
    // 目标 => 找到折叠位置
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = (right-left)/2 + left;
            // 无论如何right存在其它相等值, 可以直接忽略右端点
            if(nums[mid] == nums[right]){
                right--;
            }
            else if(nums[mid] < nums[right]){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return nums[left];
    }
};
// @lc code=end

