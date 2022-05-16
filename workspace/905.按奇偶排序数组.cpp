/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int tmp = 0;
        while(left < right){
            while(left<right && nums[left]%2==0){
                left++;
            }
            while(left<right && nums[right]%2==1){
                right--;
            }
            if(left < right){
                tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
            }
        }
        return nums;
    }
};
// @lc code=end

