/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    // 折叠数组: 一要考虑折叠位置, 二要考虑target
    // 在LC33的基础上, 允许数组存在重复元素 => 去重, 而不是在边界判断上做改变
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            while(left+1<=right && nums[left] == nums[left+1])
                left++;
while(left<=right-1 && nums[right]==nums[right-1])
            right--;
            int mid = (right-left)/2+left;
            if(nums[mid]==target)
                return true;
            else if(nums[mid] < nums[right]){   // 说明mid在右侧段上
                if(target > nums[mid] && target <= nums[right]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
            else{   // 说明mid在左侧段上
                if(target < nums[mid] && target >= nums[left]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
        }
        return false;
    }
};
// @lc code=end

