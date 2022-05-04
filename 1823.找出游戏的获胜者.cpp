/*
 * @lc app=leetcode.cn id=1823 lang=cpp
 *
 * [1823] 找出游戏的获胜者
 */

// @lc code=start
class Solution {
public:
    // 约瑟夫环: jq[i+1] = (jq[i]+m) % (i+1)
    // 也可以递归实现
    int findTheWinner(int n, int k) {
        vector<int> dp(n+1);
        dp[1] = 0;
        for(int i=1; i<n; i++){
            dp[i+1] = (dp[i]+k) % (i+1);
        }
        return dp[n]+1;
    }
};
// @lc code=end

