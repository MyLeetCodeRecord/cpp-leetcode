/*
 * @lc app=leetcode.cn id=1319 lang=cpp
 *
 * [1319] 连通网络的操作次数
 */

// @lc code=start
class Solution {
public:
    vector<int> father;
    void init(int n){
        father.resize(n);
        for(int i=0; i<n; i++)
            father[i] = i;
    }
    int find(int u){
        if(father[u] != u)
            father[u] = find(father[u]);
        return father[u];
    }
    void union2(int u, int v){
        int fu = find(u);
        int fv = find(v);
        father[fu] = fv;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        // 检查合法性
        if(connections.size() < n-1)
            return -1;
        init(n);
        for(vector<int> edge: connections){
            union2(edge[0], edge[1]);
        }
        // 答案为集合数 - 1
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(father[i] == i)
                cnt++;
        }
        return cnt-1;
    }
};
// @lc code=end

