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
        int ans = 0;
        int n = nums.size();
        vector<int> preSum(n+1, 0);
        unordered_map<int,int> sumMp;
        sumMp[0] = 1;                   // !!!
        for(int i=0; i<n; i++){
            preSum[i+1] = preSum[i] + nums[i];
            ans += sumMp[preSum[i+1]-k];
            sumMp[preSum[i+1]]++;
        }
        return ans;
    }
};
// @lc code=end

