/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    // 折叠数组: 一要考虑折叠位置, 二要考虑target
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = (right-left)/2+left;
            if(nums[mid]==target)
                return mid;
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
        return -1;
    }
};
// @lc code=end

