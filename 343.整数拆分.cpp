/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    // dp[i]是拆分 i 能得到的最大乘积
    // 假设枚举中间分界点 j, j左侧不做拆分(j), 右侧可以拆分(dp[j])
    // 每个 j 作为分界点的最大乘积 max(j*(i-j), j*dp[i-j]) 作为dp[i]的一个候选
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        for(int i=2; i<=n; i++){
            for(int j=1; j<i; j++){
                dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));
            }
        }
        return dp[n];
    }
};
// @lc code=end

