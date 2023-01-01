/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
class Solution {
public:
    int color[110];
    bool DFS(vector<vector<int>>& graph, int u, int c){
        color[u] = c;
        for(int i=0; i<graph[u].size(); i++){
            int j = graph[u][i];
            // 染色冲突
            if(color[j]==c)
                return false;
            if(color[j]==0 && DFS(graph, j, -c)==false)
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        for(int i=0; i<n; i++){
            if(color[i]==0){
                if(DFS(graph, i, 1)==false)
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end

