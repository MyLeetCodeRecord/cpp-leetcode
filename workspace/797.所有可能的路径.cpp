/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
class Solution {
public:
    // DAG: 无环, 不需要visited[]数组
    vector<vector<int> > ans;
    vector<int> path;
    void backtrack(vector<vector<int> > graph, int cur, int dest){
        if(path.back()==dest){
            ans.push_back(path);
            return ;
        }
        for(int i=0; i<graph[cur].size(); i++){
            path.push_back(graph[cur][i]);
            backtrack(graph, graph[cur][i], dest);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        path.push_back(0);
        backtrack(graph, 0, n-1);
        return ans;
    }
};
// @lc code=end

