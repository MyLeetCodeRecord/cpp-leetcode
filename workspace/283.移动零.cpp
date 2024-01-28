/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        for(const int &x: nums){
            if(x != 0)
                nums[idx++] = x;
        }
        while(idx < n){
            nums[idx++] = 0;
        }
    }
};
// @lc code=end

