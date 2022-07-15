/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class Solution {
private:
    // dead nodes不影响, 所以可以初始化大一点
    vector<int> father;
    vector<int> sizeList;
public:
    void init(int n){
        father.resize(n+1);
        sizeList.resize(n+1);
        for(int i=1; i<=n; i++){
            father[i] = i;
            sizeList[i] = 1;
        }
    }
    int find(int u){
        return (u==father[u]) ? u : find(father[u]);
    }
    void union_2(int u,int v){
        int pu = find(u);
        int pv = find(v);
        if(pu==pv)
            return ;
        father[pu] = pv;
        sizeList[pv] += sizeList[pu];
    }
    bool inSame(int u, int v){
        return find(u) == find(v);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init(1001);
        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];
            if(inSame(u, v)==true){
                return edge;
            }
            union_2(u, v);
        }
        return {};
    }
};
// @lc code=end

