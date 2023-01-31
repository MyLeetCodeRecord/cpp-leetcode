/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 *
 * [1254] 统计封闭岛屿的数目
 */

// @lc code=start
class Solution {
public:
    int n, m;
    int directions[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    // 在LC200. 岛屿数量的基础上, 区别在于「边界上的岛屿不算岛屿」
    bool DFS(vector<vector<int>> &grid, int r, int c){
        // 如果触及边缘则返回false
        if(r<0 || r>=m || c<0 || c>=n)
            return false;
        if(grid[r][c]==0){
            grid[r][c] = -1;    // 标记已访问, 不是0就可以
            bool up = DFS(grid, r-1, c);
            bool down = DFS(grid, r+1, c);
            bool left = DFS(grid, r, c-1);
            bool right = DFS(grid, r, c+1);
            return up & down & left & right;
        }
        return true;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    if(DFS(grid, i, j))
                        ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

