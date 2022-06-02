/*
 * @lc app=leetcode.cn id=473 lang=cpp
 *
 * [473] 火柴拼正方形
 */

// @lc code=start
class Solution {
public:
    // 抽象成 => 把一堆数字放入四个桶, 即分支是"每个数字选择桶"
    bool dfs(int index, vector<int> &matchsticks, vector<int> &edges, int avg) {
        if (index == matchsticks.size()) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            edges[i] += matchsticks[index];
            if (edges[i] <= avg && dfs(index + 1, matchsticks, edges, avg)) {
                return true;
            }
            edges[i] -= matchsticks[index];
        }
        return false;
    }
    bool makesquare(vector<int> &matchsticks) {
        int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (totalLen % 4 != 0)
            return false;

        sort(matchsticks.begin(), matchsticks.end(), greater<int>()); // 减少搜索量

        vector<int> edges(4, 0);
        return dfs(0, matchsticks, edges, totalLen / 4);
    }
};
// @lc code=end

