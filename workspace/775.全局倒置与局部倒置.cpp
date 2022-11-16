/*
 * @lc app=leetcode.cn id=775 lang=cpp
 *
 * [775] 全局倒置与局部倒置
 */

// @lc code=start
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        // 截止到 i 位置的最大值
        vector<int> leftMax(n, 0);
        leftMax[0] = nums[0];
        for(int i=1; i<n; i++){
            leftMax[i] = max(nums[i], leftMax[i-1]);
        }
        for(int i=2; i<n; i++){
            if(nums[i] < leftMax[i-2])
                return false;
        }
        return true;
    }
};
// @lc code=end

