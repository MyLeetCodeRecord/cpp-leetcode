/*
 * @lc app=leetcode.cn id=1626 lang=cpp
 *
 * [1626] 无矛盾的最佳球队
 */

// @lc code=start
class Solution {
    typedef pair<int, int> PII;
public:
    /*
        先排序 - 先按 age 升序, 再按 score 升序
        类似「最长递增子序列」
        - 定义: dp[i]表示以ages[i]结尾的递增子序列的最大得分
        - 状态转移: dp[i] = max⁡(dp[j]) + scores[i] (转移条件为「j和i年龄相等」或者「i.score >= j.score」)
    */
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<PII> teams;
        for(int i=0; i<n; i++){
            teams.push_back({ages[i], scores[i]});
        }
        // 先按 age 升序, 再按 score 升序
        sort(teams.begin(), teams.end());
        int ans = 0;
        vector<int> dp(n, 0);
        for(int i=0; i<n; i++){
            dp[i] = teams[i].second;
            for(int j=0; j<i; j++){
                if(teams[i].first==teams[j].first || teams[i].second >= teams[j].second)
                    dp[i] = max(dp[i], dp[j] + teams[i].second);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end

