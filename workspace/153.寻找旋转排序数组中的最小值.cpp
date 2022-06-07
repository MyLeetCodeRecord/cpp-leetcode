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
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = (right-left)/2 + left;
            // min在当前mid位置 or 左侧
            if(nums[mid] <= nums[right]){
                // 判断min是否在当前位置
                if(mid == 0 || nums[mid] < nums[mid-1])
                    return nums[mid];
                right = mid - 1;
            }
            // min在右侧, 收缩左边界
            else{
                left = mid + 1;
            }
        }
        return -1;
    }
};
// @lc code=end

