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
        vector<vector<int> > prefixSum(m+1, vector<int>(n+1, 0));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                prefixSum[i][j] = matrix[i-1][j-1] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
            }
        }
        preSum = prefixSum;
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        // 本题的query是从下标0开始的
        row1++;  col1++;
        row2++;  col2++;
        return preSum[row2][col2] - preSum[row2][col1-1] - preSum[row1-1][col2] + preSum[row1-1][col1-1];
    }
};
// @lc code=end

