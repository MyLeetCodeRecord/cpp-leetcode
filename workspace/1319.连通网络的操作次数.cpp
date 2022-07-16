/*
 * @lc app=leetcode.cn id=1319 lang=cpp
 *
 * [1319] 连通网络的操作次数
 */

// @lc code=start
class Solution {
private:
    vector<int> father;
    vector<int> sizeList;
    int ufsCnt;
public:
    void init_ufs(int n){
        ufsCnt = n;
        father.resize(n);
        sizeList.resize(n);
        for(int i=0; i<n; i++){
            father[i] = i;
            sizeList[i] = 1;
        }
    }
    int find(int u){
        return (u==father[u]) ? u : find(father[u]);
    }
    void union_2(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu==pv)
            return ;
        sizeList[pv] += sizeList[pu];
        father[pu] = pv;
        ufsCnt--;
    }
    bool inSame(int u, int v){
        return find(u)==find(v);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        // 使n个点连通至少需要n-1条边
        if(connections.size() < n-1)
            return -1;
        init_ufs(n);
        for(vector<int> edge: connections){
            union_2(edge[0], edge[1]);
        }
        return ufsCnt-1;
    }
};
// @lc code=end

