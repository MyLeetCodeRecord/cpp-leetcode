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
        int n = nums.size();
        int l = 0, r = n-1;
        while(l < r){
            int mid = (l+r)/2;
            if(nums[mid] == target)
                return mid;
            // 左边有序, 右边折叠
            if(nums[mid] >= nums[l]){
                if(nums[mid]>target && nums[l]<=target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            // 右边有序, 左边折叠
            else{
                if(nums[mid]<target && nums[r]>=target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return (l<n && nums[l]==target) ? l : -1;
    }
// @lc code=end

