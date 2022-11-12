/*
 * @lc app=leetcode.cn id=790 lang=cpp
 *
 * [790] 多米诺和托米诺平铺
 */

// @lc code=start
class Solution {
public:
    int numTilings(int n) {
        // 状态0: 00
        // 状态1: 01
        // 状态2: 10
        // 状态3: 11
        int dp[n+1][4];
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = 0;
        dp[0][3] = 1;
        for(int i=1; i<=n; i++){
            dp[i][0] = dp[i-1][3] % 1000000007;
            dp[i][1] = (dp[i-1][2] + dp[i-1][0]) % 1000000007;
            dp[i][2] = (dp[i-1][1] + dp[i-1][0]) % 1000000007;
            // 注意这里逐层取mod
            dp[i][3] = (((dp[i-1][0] + dp[i-1][1]) % 1000000007 + dp[i-1][2]) % 1000000007 + dp[i-1][3]) % 1000000007;
        }
        return dp[n][3];
    }
};
// @lc code=end

