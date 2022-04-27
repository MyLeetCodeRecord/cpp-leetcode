/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
class Solution {
private:
    int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    void DFS(vector<vector<int> >& heights, vector<vector<bool>>& mark, int row, int col){  // mark要记得加引用
        mark[row][col] = true;  // 标记
        for(int d=0; d<4; d++){
            int nextRow = row + directions[d][0];
            int nextCol = col + directions[d][1];
            if(nextRow>=0 && nextRow<heights.size() && nextCol>=0 && nextCol<heights[0].size() && mark[nextRow][nextCol] == false){
                if(heights[nextRow][nextCol] >= heights[row][col]){    // 升序才能DFS
                    DFS(heights, mark, nextRow, nextCol);
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        // 区分两个大洋 -> 作为DFS参数传进去
        vector<vector<bool> > Pacific(m, vector<bool>(n, false));
        vector<vector<bool> > Atlantic(m, vector<bool>(n, false));

        // 从岸边出发, 升序DFS
        for(int i=0; i<m; i++){
            DFS(heights, Pacific, i, 0);
            DFS(heights, Atlantic, i, n-1);
        }
        for(int j=0; j<n; j++){
            DFS(heights, Pacific, 0, j);
            DFS(heights, Atlantic, m-1, j);
        }
        vector<vector<int> > ans;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(Pacific[i][j]==true && Atlantic[i][j]==true){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
// @lc code=end
