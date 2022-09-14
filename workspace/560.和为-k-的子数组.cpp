/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    // 前缀和
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefixSum(nums.size()+1, 0);
        for(int i=1; i<=nums.size(); i++){
            prefixSum[i] = prefixSum[i-1]+nums[i-1];
            // map不能在这里直接计数构造, 因为统计时只搜索"前面的"
        }
        int ans = 0;
        unordered_map<int, int> cntMp;
        cntMp[0] = 1;              // !!!
        for(int i=1; i<prefixSum.size(); i++){
            if(cntMp.find(prefixSum[i]-k) != cntMp.end())
                ans += cntMp[prefixSum[i]-k];
            cntMp[prefixSum[i]]++;
        }
        return ans;
    }
};
// @lc code=end

