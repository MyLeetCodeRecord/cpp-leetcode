/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    /* Topology - BFS, 邻接表表示, 统计入度
     * [a, b]: b->a的有向边
     * Acwing: https://www.acwing.com/activity/content/code/content/4433750/
     */
    vector<int> Topo_BFS(vector<vector<int> > edges, vector<int> indegree){
        vector<int> ans;    // 出队顺序就是拓扑序
        queue<int> q;
        for(int i=0; i<edges.size(); i++){
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(int v: edges[u]){
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
            }
        }
        if(ans.size()==edges.size())
            return ans;
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 邻接表存储, 并记录indegree[]数组
        vector<vector<int>> edges(numCourses);
        vector<int> indegree(numCourses, 0);
        for(vector<int> pre: prerequisites){
            indegree[pre[0]]++;
            edges[pre[1]].push_back(pre[0]);
        }
        return Topo_BFS(edges, indegree);
    }
};
// @lc code=end

