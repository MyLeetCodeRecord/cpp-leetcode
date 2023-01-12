/*
 * @lc app=leetcode.cn id=778 lang=cpp
 *
 * [778] 水位上升的泳池中游泳
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
    // 0 <= grid[i][j] < n^2, 并且grid[i][j]不重复
    // 于是可知从 0~n-1 每个高度和每个节点存在一一对应的关系
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        init(n*n);
        // 第一维: 高度(时间)
        // 第二维: 压缩后的位置坐标
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mp[grid[i][j]] = i*n+j;
            }
        }
        for(int t=0; ; t++){
            int i = mp[t] / n;
            int j = mp[t] % n;
            // 连通所有更低的相邻节点
            if(i-1>=0 && grid[i-1][j] < t)  // 上
                union2(mp[t], mp[t]-n);
            if(i+1<n && grid[i+1][j] < t)   // 下
                union2(mp[t], mp[t]+n);
            if(j-1>=0 && grid[i][j-1] < t)  // 左
                union2(mp[t], mp[t]-1);
            if(j+1<n && grid[i][j+1] < t)   // 右
                union2(mp[t], mp[t]+1);
            // 结束条件: (0,0)和(n-1,n-1)所在集合连通起来了
            if(find(0) == find(n*n-1))
                return t;
        }
        return 0;
    }
};
// @lc code=end

