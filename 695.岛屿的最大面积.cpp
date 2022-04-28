/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
    // DFS
    void DFS(vector<vector<int> >& grid, int& cnt, int row, int col){
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col]!=1)
            return ;
        cnt++;
        grid[row][col] = -1;   // 标记已访问的节点, 省略visit数组
        DFS(grid, cnt, row+1, col);
        DFS(grid, cnt, row-1, col);
        DFS(grid, cnt, row, col+1);
        DFS(grid, cnt, row, col-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int areaCnt = 0;
                    DFS(grid, areaCnt, i, j);
                    ans = max(ans, areaCnt);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

