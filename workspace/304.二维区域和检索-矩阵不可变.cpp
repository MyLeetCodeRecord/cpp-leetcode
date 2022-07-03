/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix {
private:
    vector<vector<int> > preSum;
    int m, n;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int> > prefixSum(m, vector<int>(n, 0));
        prefixSum[0][0] = matrix[0][0];
        for(int i=1; i<m; i++){
            prefixSum[i][0] = matrix[i][0] + prefixSum[i-1][0];
        }
        for(int j=1; j<n; j++){
            prefixSum[0][j] = matrix[0][j] + prefixSum[0][j-1];
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                prefixSum[i][j] = matrix[i][j] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
            }
        }
        preSum = prefixSum;
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1==0 && col1==0)
            return preSum[row2][col2];
        if(row1==0)
            return preSum[row2][col2] - preSum[row2][col1-1];
        if(col1==0)
            return preSum[row2][col2] - preSum[row1-1][col2];
        return preSum[row2][col2] - preSum[row1-1][col2] - preSum[row2][col1-1] + preSum[row1-1][col1-1];
    }
};
// @lc code=end

