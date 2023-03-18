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
    // (去重可以解决问题, 但没有恢复二段性)
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l < r){
            // 先去重
            while(l<r && nums[l]==nums[l+1])
                l++;
            while(l<r && nums[r]==nums[r-1])
                r--;
            int mid = (l+r)/2;
            if(nums[mid] == target)
                return true;
            // 左边有序, 右边折叠
            if(nums[l] <= nums[mid]){
                if(target >= nums[l] && nums[mid] > target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            // 右边有序, 左边折叠
            else{
                if(target <= nums[r] && nums[mid] < target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return (l<n && nums[l]==target);
    }
};
// @lc code=end

