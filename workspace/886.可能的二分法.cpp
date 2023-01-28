/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 */

// @lc code=start
class Solution {
public:
    vector<int> father;
    void init(int n){
        father.resize(n+1);
        for(int i=1; i<=n; i++)
            father[i] = i;
    }
    int find(int u){
        if(u != father[u])
            father[u] = find(father[u]);
        return father[u];
    }
    void union2(int u, int v){
        int fu = find(u);
        int fv = find(v);
        father[fu] = fv;
    }
    bool inSame(int u, int v){
        int fu = find(u);
        int fv = find(v);
        return fu==fv;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        init(n);
        vector<vector<int>> hates(n+1);
        for(vector<int> &e: dislikes){
            hates[e[1]].push_back(e[0]);
            hates[e[0]].push_back(e[1]);
        }
        for(int i=1; i<=n; i++){
            for(int j=0; j<hates[i].size(); j++){
                union2(hates[i][0], hates[i][j]);
                if(inSame(i, hates[i][j]))
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end

