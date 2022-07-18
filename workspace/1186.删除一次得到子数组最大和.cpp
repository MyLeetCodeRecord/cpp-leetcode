/*
 * @lc app=leetcode.cn id=1186 lang=cpp
 *
 * [1186] 删除一次得到子数组最大和
 */

// @lc code=start
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        vector<vector<int> > dp(2, vector<int>(arr.size(), 0));
        dp[0][0] = arr[0];
        dp[1][0] = 0;
        int ans = max(dp[0][0], dp[1][0]);
        for(int i=1; i<arr.size(); i++){
            dp[0][i] = max(dp[0][i-1] + arr[i], arr[i]);
            dp[1][i] = max(dp[0][i-1], dp[1][i-1]+arr[i]);
            ans = max(ans, max(dp[0][i], dp[1][i]));
        }
        return ans;
    }
};
// @lc code=end

