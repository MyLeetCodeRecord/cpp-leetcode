/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
private:
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums) {
        prefixSum.resize(nums.size());
        fill(prefixSum.begin(), prefixSum.end(), 0);
        prefixSum[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            prefixSum[i] = prefixSum[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(right>=prefixSum.size())
            return prefixSum.back();
        if(left==0)
            return prefixSum[right];
        else
            return prefixSum[right]-prefixSum[left-1];
    }
};
// @lc code=end

