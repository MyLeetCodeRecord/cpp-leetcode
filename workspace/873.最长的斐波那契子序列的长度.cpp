/*
 * @lc app=leetcode.cn id=873 lang=cpp
 *
 * [873] 最长的斐波那契子序列的长度
 */

// @lc code=start
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // map: 用于查询 k=arr[i]-arr[j] 是否存在
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
            dp[i][i] = 1;   // 其实不需要, 因为arr不存在相同元素, [2,2,2...]这种答案不会出现        }
        }
        int ans = 2;
        for(int j=1; j<n; j++){
            for(int i=0; i<j; i++){
                dp[i][j] = 2;
                if(mp.find(arr[j]-arr[i])!=mp.end()){
                    int k = mp[arr[j] - arr[i]];
                    if(k < i)
                        dp[i][j] = max(dp[i][j], dp[k][i] + 1);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans>=3 ? ans : 0;
    }
};
// @lc code=end

