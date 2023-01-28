/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 */

// @lc code=start
// CV

class Solution {
private:
    vector<int> father;
    int n; // 边的数量
    void init(int n) {
        father.resize(n+1);
        for (int i = 1; i <= n; ++i) {
            father[i] = i;
        }
    }
    int find(int u) {
        if(u != father[u])
            father[u] = find(father[u]);
        return father[u];
    }
    void union2(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v)
            father[v] = u;
    }
    // 判断 u 和 v是否找到同一个根
    bool inSame(int u, int v) {
        int fu = find(u);
        int fv = find(v);
        return fu == fv;
    }
    // 在有向图里找到删除的那条边, 即找到使图中存在环的边
    vector<int> getRemoveEdge(const vector<vector<int>>& edges) {
        init(n); // 初始化并查集
        for (int i = 0; i < n; i++) {
            if (inSame(edges[i][0], edges[i][1]))  // 构成有向环了，就是要删除的边
                return edges[i];
            union2(edges[i][0], edges[i][1]);
        }
        return {};
    }
    // 判断删一条边之后判断是不是树
    bool isTreeAfterRemoveEdge(const vector<vector<int>>& edges, int deleteEdge) {
        init(n); // 初始化并查集
        for (int i = 0; i < n; i++) {
            if (i == deleteEdge) continue;
            if (inSame(edges[i][0], edges[i][1])) { // 构成有向环了，一定不是树
                return false;
            }
            union2(edges[i][0], edges[i][1]);
        }
        return true;
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        n = edges.size();
        vector<int> inDegree(n+1, 0);
        for (int i = 0; i < n; i++) {
            inDegree[edges[i][1]]++; // 统计入度
        }
        // case1: 如果有入度为2的节点,那么一定是两条边里删一个, 看删哪个可以构成树
        vector<int> twoEdges; // 记录入度为2的边（如果有的话就两条边）
        for(int i = n - 1; i >= 0; i--) {  // 注意要倒序
            if(inDegree[edges[i][1]] == 2)
                twoEdges.push_back(i);
        }
        if(twoEdges.size() > 0){
            if(isTreeAfterRemoveEdge(edges, twoEdges[0]))
                return edges[twoEdges[0]];
            else
                return edges[twoEdges[1]];
        }
        // case2: 没有入度为2的情况, 那么一定有有向环, 找到构成环的边返回就可以了
        return getRemoveEdge(edges);
    }
};
// @lc code=end
