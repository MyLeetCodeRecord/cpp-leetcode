/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        prefixSum.resize(nums.size()+1);
        fill(prefixSum.begin(), prefixSum.end(), 0);
        for(int i=1; i<=nums.size(); i++){
            prefixSum[i] = prefixSum[i-1]+nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right+1]-prefixSum[left];
    }
};
// @lc code=end

