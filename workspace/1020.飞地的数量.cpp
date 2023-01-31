/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
class Solution {
public:
    // 同LC130. 被围绕的区域
    int m, n;
    int directions[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    void DFS(vector<vector<int>> &grid, int r, int c){
        if(r<0||r>=m||c<0||c>=n||grid[r][c]!=1)
            return ;
        grid[r][c] = -1;
        for(int i=0; i<4; i++){
            int nextR = r + directions[i][0];
            int nextC = c + directions[i][1];
            DFS(grid, nextR, nextC);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i=0; i<m; i++){
            DFS(grid, i, 0);
            DFS(grid, i, n-1);
        }
        for(int j=0; j<n; j++){
            DFS(grid, 0, j);
            DFS(grid, m-1, j);
        }
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1)
                    cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end

