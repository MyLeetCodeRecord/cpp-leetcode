/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class Solution {
private:
    vector<int> father;
public:
    void init(int n){
        for(int i=1; i<=n; i++)
            father[i] = i;
    }
    int find(int u){
        if(u != father[u])
            father[u] = find(father[u]);    // 路径压缩
        return father[u];
    }
    // 在union中返回一个bool值, 可以直接代替inSame的作用
    void union_2(int u,int v){
        int pu = find(u);
        int pv = find(v);
        if(pu==pv)
            return true;
        father[pu] = pv;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        init(n);
        for(vector<int> edge: edges){
            bool duplicate = union_2(edge[0], edge[1]);
            if(duplicate)
                return edge;
        }
        return {};
    }
};
// @lc code=end

