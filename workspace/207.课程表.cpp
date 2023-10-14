/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    /* Topology - BFS, 邻接表(vector<vector<int>>)表示, 统计入度
     * [a, b]: b->a的有向边
     * Acwing: https://www.acwing.com/activity/content/code/content/4433750/
     */
    
    bool Topo_BFS(vector<vector<int>> &edges, vector<int> &indegree){
        vector<int> ans;    // 出队顺序就是一种可能的拓扑序
        queue<int> q;
        for(int i=0; i<edges.size(); i++){
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int a: edges[cur]){
                indegree[a]--;
                if(indegree[a] == 0){
                    q.push(a);
                    cnt++;
                }
            }
        }
        return ans.size()==indegree.size();
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // vector<vector<int> > 组织的邻接表
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

