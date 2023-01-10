/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

// @lc code=start
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eqs, vector<double>& vals, vector<vector<string>>& queries) {
        // 构建图的邻接表存储
        unordered_map<string, vector<pair<string, double>>> graph;
        int n = eqs.size();
        for(int i=0; i<n; i++){
            graph[eqs[i][0]].push_back({eqs[i][1], vals[i]});
            graph[eqs[i][1]].push_back({eqs[i][0], 1.0/vals[i]});
        }
        vector<double> ans(queries.size(), -1.0);
        for(int i=0; i<queries.size(); i++){
            string st = queries[i][0];
            string ed = queries[i][1];
            // 非法节点, ans[i] = -1.0
            if(graph.find(st)==graph.end() && graph.find(ed)==graph.end()){
                ans[i] = -1.0;
                continue;
            }
            // 合法节点 & 起终点相同, ans[i] = 1.0
            if(st == ed){
                ans[i] = 1.0;
                continue;
            }
            // BFS
            queue<pair<string, double>> q;
            q.push({st, 1});
            unordered_set<string> visited;
            visited.insert(st);
            while(!q.empty()){
                pair<string, double> cur = q.front();
                q.pop();
                if(cur.first == ed){
                    ans[i] = cur.second;
                    break;
                }
                for(pair<string, double> edge: graph[cur.first]){
                    if(visited.find(edge.first)==visited.end()){
                        visited.insert(edge.first);
                        q.push({edge.first, cur.second * edge.second});
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

