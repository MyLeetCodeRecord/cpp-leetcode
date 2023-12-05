/*
 * @lc app=leetcode.cn id=2477 lang=cpp
 *
 * [2477] 到达首都的最少油耗
 */

// @lc code=start
class Solution {
public:
    long long ans = 0;
    long long DFS(vector<vector<int>>& graph, int cur, int pre, int seats){
        long long sum = 1;
        for(int neighbor: graph[cur]){
            if(neighbor != pre){
                sum += DFS(graph, neighbor, cur, seats);
            }
        }
        if(cur != 0)
            ans += (sum + seats - 1) / seats;
        return sum;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        // 建图, 邻接表
        vector<vector<int>> graph(roads.size()+1);
        for(vector<int> &road : roads){
            int a = road[0], b = road[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        // 递归
        DFS(graph, 0, -1, seats);
        return ans;
    }
};
// @lc code=end

