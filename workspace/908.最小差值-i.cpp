/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 */

// @lc code=start
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxVal = nums[0];
        int minVal = nums[0];
        for(int n: nums){
            minVal = min(minVal, n);
            maxVal = max(maxVal, n);
        }
        return (maxVal-minVal-2*k)>0 ? (maxVal-minVal-2*k) : 0;
    }
};
// @lc code=end

