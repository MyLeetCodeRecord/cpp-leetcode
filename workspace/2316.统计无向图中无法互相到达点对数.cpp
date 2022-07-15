/*
 * @lc app=leetcode.cn id=2316 lang=cpp
 *
 * [2316] 统计无向图中无法互相到达点对数
 */

// @lc code=start
class Solution {
    vector<vector<int>> e;
    vector<bool> vis;

    int bfs(int S) {
        int ret = 0;
        queue<int> q;
        q.push(S); vis[S] = true;
        while (!q.empty()) {
            ret++;
            int sn = q.front(); q.pop();
            for (int fn : e[sn]) if (!vis[fn]) q.push(fn), vis[fn] = true;
        }
        return ret;
    }

public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        e.resize(n, vector<int>());
        vis.resize(n, false);
        for (auto &edge : edges) e[edge[0]].push_back(edge[1]), e[edge[1]].push_back(edge[0]);

        long long ans = 0;
        for (int i = 0; i < n; i++) if (!vis[i]) {
            int t = bfs(i);
            ans += 1LL * t * (n - t);
        }
        return ans / 2;
    }
};
// @lc code=end

