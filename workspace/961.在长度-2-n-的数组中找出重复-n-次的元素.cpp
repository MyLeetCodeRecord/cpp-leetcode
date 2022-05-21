/*
 * @lc app=leetcode.cn id=961 lang=cpp
 *
 * [961] 在长度 2N 的数组中找出重复 N 次的元素
 */

// @lc code=start
class Solution {
public:
    // 不用额外map空间, 必然存在一个长度为3的区间, 有重复元素出现
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        // 间隔为2时长度将达到(3n-2)  => 间隔不可能超过2 (间隔 = 下标差距 - 1), 即最多检查到(x o o x)即可
        for(int gap = 0; gap <= 2; gap++) {
            for(int i = 0; i + gap +1 < n; i++) {
                if(nums[i] == nums[i + gap + 1]) {
                    return nums[i];
                }
            }
        }
        return -1;
    }
};
// @lc code=end

