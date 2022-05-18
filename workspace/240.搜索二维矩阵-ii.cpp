/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
private:
    int m, n;
public:
    bool search(vector<vector<int> >& matrix, int startRow, int endCol, int target){
        if(startRow >= m || endCol < 0)
            return false;
        int cur = matrix[startRow][endCol];
        if(cur == target)
            return true;
        if(cur > target)
            return search(matrix, startRow, endCol-1, target);
        else
            return search(matrix, startRow+1, endCol, target);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m = matrix.size();
        n = matrix[0].size();
        return search(matrix, 0, n-1, target);
    }
};
// @lc code=end

