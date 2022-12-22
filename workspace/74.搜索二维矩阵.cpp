/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();      // 3
        int n = matrix[0].size();   // 4
        int l = 0;
        int r = m*n-1;
        while(l < r){
            int mid = (l+r)/2;
            // 1d -> 2d
            int row = mid / n;
            int col = mid % n;
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] < target)
                l = mid + 1;
            else
                r = mid;
        }
        // 有可能没进去上面的循环 e.g. [[1]]  1
        int row = l / n;
        int col = l % n;
        return matrix[row][col]==target;
    }
};
// @lc code=end

