/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    // up维护当前元素位于上升区间的最长摆动序列长度
    // down维护当前元素位于下降区间的最长摆动序列长度
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int up = 1;
        int down = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                up = down + 1;
            } 
            else if (nums[i] < nums[i - 1]) {
                down = up + 1;
            }
        }
        return max(up, down);
    }
};
// @lc code=end

