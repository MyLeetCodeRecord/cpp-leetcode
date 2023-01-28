/*
 * @lc app=leetcode.cn id=802 lang=cpp
 *
 * [802] 找到最终的安全状态
 */

// @lc code=start
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        // 1. 构建反向图, 并记录反向图的indegree信息
        vector<vector<int>> g(n);
        vector<int> indegree(n, 0);
        for(int i=0; i<graph.size(); i++){
            for(int to: graph[i]){
                g[to].push_back(i);
                indegree[i]++;
            }
        }
        // 2. 求拓扑序列过程 (BFS)
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int v: g[cur]){
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
            }
        }
        // indegree=0的节点为安全节点
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(indegree[i]==0)
                ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end

