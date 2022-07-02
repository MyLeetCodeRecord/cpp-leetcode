/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    // nums[i]可能小于0, 因此不可以用双指针/滑动窗口
    // 前缀和
    int subarraySum(vector<int>& nums, int k) {
        // 1. 求前缀和(错开一位也方便后面计算区间和)
        vector<int> prefixSum(nums.size()+1, 0);
        prefixSum[0] = 0;
        for(int i=1; i<=nums.size(); i++){
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }
        // 2. map记录前缀和
        unordered_map<int, int> mp;
        int ans = 0;
        mp[0] = 1;
        for(int i=1; i<=nums.size(); i++){
            if(mp.find(prefixSum[i]-k)!=mp.end())
                ans += mp[prefixSum[i]-k];
            mp[prefixSum[i]]++;
        }
        return ans;
    }
};
// @lc code=end

