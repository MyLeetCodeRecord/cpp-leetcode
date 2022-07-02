/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 计算差分
        int maxLen = 0;
        vector<int> diff(1001, 0);
        for(vector<int> t: trips){
            diff[t[1]-1] += t[0];
            if(t[2] < 1001)
                diff[(t[2]-1)+1] -= t[0];
            maxLen = max(maxLen, max(t[1], t[2]));
        }
        // 如果不创建额外空间prefixSum可以直接覆盖在diff上
        vector<int> prefixSum(maxLen, 0);
        prefixSum[0] = diff[0];
        for(int i=1; i<maxLen; i++){
            prefixSum[i] = prefixSum[i-1]+diff[i];
            if(prefixSum[i] > capacity)
                return false;
        }
        return true;
    }
};
// @lc code=end

