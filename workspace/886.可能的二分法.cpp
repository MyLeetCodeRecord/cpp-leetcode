/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 */

// @lc code=start
class Solution {
private:
    vector<int> father;
public:
    void init_ufs(int n){
        father.resize(n);
        for(int i=0; i<n; i++){
            father[i] = -1;
        }
    }
    int find(int u){
        return (u==father[u]) ? u : find(father[u]);
    }
    int find2(int u){
        while(u!=father[u]){
            u = father[u];
        }
        return u;
    }
    void union_ufs(int u, int v){
        int pu = find(u);
        int pv = find(v);
        father[pu] = pv;
    }
    bool inSame(int u, int v){
        return find(u) == find(v)
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        init_ufs();
        vector<vector<int>> g(n + 1);
        for (auto& p : dislikes) {
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        for (int i=1; i<=n; i++) {
            for (int j=0; j<g[i].size(); j++) {
                union_ufs(g[i][0], g[i][j]);
                if(inSame(i, g[i][j])) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

