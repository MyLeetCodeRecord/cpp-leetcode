/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    // 有序, 无重复 => 二分
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid = (right-left)/2+left;
            // 存在都可以通过这里返回
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        // 不存在返回-1
        return -1;
    }
};
// @lc code=end

