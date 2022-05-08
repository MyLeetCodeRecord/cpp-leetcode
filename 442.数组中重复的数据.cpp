/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */

// @lc code=start
class Solution {
public:    
    // 方法二: 原地标记
    vector<int> findDuplicates(vector<int>& nums) {
        const int N = nums.size();
        vector<int> res;
        for (int i = 0; i < N; i++) {
            if (nums[abs(nums[i]) - 1] < 0)
                res.push_back(abs(nums[i]));
            nums[abs(nums[i]) - 1] *= -1;
        }
        return res;
    }
};
// @lc code=end

