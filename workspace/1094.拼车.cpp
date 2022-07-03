/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 计算差分(Index 从 0 开始)
        int maxLen = 0;
        vector<int> diff(1001, 0);
        for(vector<int> t: trips){
            diff[t[1]] += t[0];
            diff[t[2]] -= t[0];
            maxLen = max(maxLen, max(t[1], t[2]));
        }
        // 这里的前缀和省略为两个cumSum即可
        // int cumSum = diff[0];
        vector<int> prefixSum(maxLen+1, 0);
        prefixSum[0] = diff[0];
        if(prefixSum[0] > capacity)
            return false;
        for(int i=1; i<=maxLen; i++){
            prefixSum[i] = prefixSum[i-1]+diff[i];
            if(prefixSum[i] > capacity)
                return false;
        }
        return true;
    }
};
// @lc code=end

