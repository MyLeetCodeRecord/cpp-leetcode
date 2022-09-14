/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // 前缀和(错开一位)
        vector<int> prefixSum(nums.size()+1, 0);
        for(int i=1; i<=nums.size(); i++){
            prefixSum[i] = nums[i-1] + prefixSum[i-1];
        }
        // 找满足条件的下标 i
        for(int i=0; i<nums.size(); i++){
            if(prefixSum[i]*2 == prefixSum.back()-nums[i])
                return i;
        }
        return -1;
    }
};
// @lc code=end

