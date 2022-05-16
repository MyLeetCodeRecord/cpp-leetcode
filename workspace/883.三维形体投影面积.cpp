/*
 * @lc app=leetcode.cn id=883 lang=cpp
 *
 * [883] 三维形体投影面积
 */

// @lc code=start
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int xy_area = 0;
        int xz_area = 0;
        int yz_area = 0;
        int m = grid.size();        // x范围
        int n = grid[0].size();     // y范围
        vector<int> yz_highest(n, 0);
        for(int i=0; i<m; i++){
            int xz_highest = 0;
            for(int j=0; j<n; j++){
                xz_highest = max(xz_highest, grid[i][j]);
                yz_highest[j] = max(yz_highest[j], grid[i][j]);
                xy_area += (grid[i][j]!=0);
            }
            xz_area += xz_highest;
        }
        for(int z: yz_highest){
            yz_area += z;
        }
        return xy_area + xz_area + yz_area;
    }
};
// @lc code=end

