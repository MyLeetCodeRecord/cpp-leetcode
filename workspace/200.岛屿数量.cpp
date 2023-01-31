/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int m, n;
    int directions[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    void DFS(vector<vector<char>> &grid, int r, int c){
        if(r<0 || r>=m || c<0 || c>=n || grid[r][c]!='1')
            return ;
        grid[r][c] = '*';
        for(int i=0; i<4; i++){
            int nxtR = r+directions[i][0];
            int nxtC = c+directions[i][1];
            DFS(grid, nxtR, nxtC);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    DFS(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

