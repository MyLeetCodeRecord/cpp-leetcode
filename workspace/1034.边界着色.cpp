/*
 * @lc app=leetcode.cn id=1034 lang=cpp
 *
 * [1034] 边界着色
 */

// @lc code=start
class Solution {
public:
    int m, n;
    int directions[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    void DFS(vector<vector<int>> &grid, vector<vector<bool>> &connectedArea, int x, int y, int originColor, int c){
        if(x<0 || x>=m || y<0 || y>=n || grid[x][y]!=originColor)
            return ;
        // 无脑染色, 并记录整个连通区域的所有点
        // 判断边界过程不在DFS中做: 最后根据标记数组connectedArea一起判断是否是内部点, 如果是内部点, 恢复成originColor
        grid[x][y] = c;
        connectedArea[x][y] = true;
        for(int i=0; i<4; i++){
            int nextX = x + directions[i][0];
            int nextY = y + directions[i][1];
            DFS(grid, connectedArea, nextX, nextY, originColor, c);
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        m = grid.size();
        n = grid[0].size();
        int originColor = grid[row][col];
        // 如果newColor与连通分量颜色相同, 可以直接返回
        if(originColor == color)
            return grid;
        vector<vector<bool>> connectedArea(m, vector<bool>(n, false));
        DFS(grid, connectedArea, row, col, originColor, color);
        // 恢复被错误染色的内部节点, 不需要判断矩阵边缘上的点(一定是连通分量边界)
        for(int i=1; i<m-1; i++){
            for(int j=1; j<n-1; j++){
                if (connectedArea[i][j]==true && connectedArea[i-1][j]==true && connectedArea[i+1][j]==true && connectedArea[i][j-1]==true && connectedArea[i][j+1]==true) {
                    grid[i][j] = originColor;
                }
            }
        }
        return grid;
    }
};
// @lc code=end

