/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    // DFS + 省略visit数组
    void DFS(vector<vector<char> >& grid, int row, int col){    // 将grid[i][j]设为0可以起到visit数组的作用, 记得加引用&
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size())
            return ;
        if(grid[row][col]=='0')
            return ;
        grid[row][col] = '0';
        DFS(grid, row-1, col);
        DFS(grid, row, col-1);
        DFS(grid, row+1, col);
        DFS(grid, row, col+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
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

