/*
 * @lc app=leetcode.cn id=959 lang=cpp
 *
 * [959] 由斜杠划分区域
 */

// @lc code=start
class Solution {
public:
    // 每一个「1*1的小方格」可以按对角线分开为四个三角形
    //  -------
    // | *   * |   上右下左分别标号为0123
    // |   *   |
    // | *   * |
    //  -------
    // 并查集
    vector<int> father;     // 4*节点数量
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
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        init(n * n * 4);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int cubeID = i * n + j;
                // 合并「方块间」
                if(i < n-1){        // 向下合并 3 & 0
                    int downID = cubeID + n;
                    union2(cubeID * 4 + 2, downID * 4 + 0);
                }
                if(j < n-1){        // 向右合并 1 & 3
                    int rightID = cubeID + 1;
                    union2(cubeID * 4 + 1, rightID * 4 + 3);
                }
                // 合并「方块内」
                if(grid[i][j] == '/'){          // 合并 0 & 3, 1 & 2
                    union2(cubeID * 4 + 0, cubeID * 4 + 3);
                    union2(cubeID * 4 + 1, cubeID * 4 + 2);
                }
                else if(grid[i][j] == '\\'){    // 合并 0 & 1, 2 & 3
                    union2(cubeID * 4 + 0, cubeID * 4 + 1);
                    union2(cubeID * 4 + 2, cubeID * 4 + 3);
                }
                else{                           // 合并整个方块
                    union2(cubeID * 4 + 0, cubeID * 4 + 1);
                    union2(cubeID * 4 + 1, cubeID * 4 + 2);
                    union2(cubeID * 4 + 2, cubeID * 4 + 3);
                }
            }
        }
        int ans = 0;
        for(int u=0; u<n*n*4; u++){
            if(father[u] == u)
                ans++;
        }
        return ans;
    }
};
// @lc code=end

