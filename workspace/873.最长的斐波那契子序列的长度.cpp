/*
 * @lc app=leetcode.cn id=873 lang=cpp
 *
 * [873] 最长的斐波那契子序列的长度
 */

// @lc code=start
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        // 方便查询 arr[i]-arr[j] 是否存在
        unordered_map<int, int> mp;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ans = 0;
        // dp[i][j]需要使用dp[k][j], 因此令i递增
        for (int i = 1; i < n; i++) {
            // arr严格递增, 且k<j, 所以j满足arr[j]*2 > arr[i]
            for (int j = i - 1; j >= 0 && arr[j] * 2 > arr[i]; j--) {
                int k = -1;
                if (mp.find(arr[i]-arr[j]) != mp.end()) {
                    k = mp[arr[i]-arr[j]];
                }
                // 存在 k, 更新dp[i][j] = max(dp[j][k],3)
                if (k >= 0) {
                    dp[j][i] = max(dp[k][j] + 1, 3);
                }
                ans = max(ans, dp[j][i]);
            }
        }
        return ans;
    }
};
// @lc code=end

