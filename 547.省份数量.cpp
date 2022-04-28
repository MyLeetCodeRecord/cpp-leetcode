/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
class Solution {
public:
    // DFS
    void DFS(vector<vector<int> >& isConnected, vector<bool>& visit, int cur){
        visit[cur] = true;
        for(int i=0; i<isConnected.size(); i++){
            if(visit[i]==false && isConnected[cur][i]==1){
                DFS(isConnected, visit, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();
        vector<bool> visit(n, false);
        for(int i=0; i<n; i++){
            if(visit[i] == false){
                DFS(isConnected, visit, i);
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

