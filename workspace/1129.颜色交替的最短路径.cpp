/*
 * @lc app=leetcode.cn id=1129 lang=cpp
 *
 * [1129] 颜色交替的最短路径
 */

// @lc code=start
class Solution {
    typedef pair<int, int> PII;
public:
    // 最短路径 -> BFS
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<PII>> graph(n, vector<PII>());
        for(vector<int> &r : redEdges){
            graph[r[0]].push_back({r[1], 0});
        }
        for(vector<int> &b : blueEdges){
            graph[b[0]].push_back({b[1], 1});
        }
        vector<vector<int>> dist(n, vector<int>(2, INT_MAX)); 
        queue<PII> q;
        q.push({0, 0});     dist[0][0] = 0;
        q.push({0, 1});     dist[0][1] = 0;
        int layer = 0;
        while(!q.empty()){
            layer++;
            int _size = q.size();
            for(int i=0; i<_size; i++){
                PII cur = q.front();
                q.pop();
                for(auto& [v, color]: graph[cur.first]){
                    if(color != cur.second && dist[v][color] < layer){
                        q.push({v, color});
                        dist[v][color] = min(dist[v][color], layer);
                    }
                }
            }
        }
        vector<int> ans(n); // 答案数组
        for(int i=0; i<n; i++){
            ans[i] = min(dist[i][0], dist[i][1]); // 最后的答案是两者取 min
            if(ans[i]>=INT_MAX)
                ans[i] = -1;
        }
        return ans;
    }
};
// @lc code=end

