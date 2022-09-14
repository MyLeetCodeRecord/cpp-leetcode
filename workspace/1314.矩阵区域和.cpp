/*
 * @lc app=leetcode.cn id=1314 lang=cpp
 *
 * [1314] 矩阵区域和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int> > initPrefixSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int> > prefixSum(m+1, vector<int>(n+1, 0));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                prefixSum[i][j] = matrix[i-1][j-1] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
            }
        }
        return prefixSum;
    }
    int getOneArea(vector<vector<int> >& preSum, int row1, int col1, int row2, int col2) {
        return preSum[row2][col2] - preSum[row1-1][col2] - preSum[row2][col1-1] + preSum[row1-1][col1-1];
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int> > preSum = initPrefixSum(mat);
        vector<vector<int> > ans(m, vector<int>(n, 0));
        // 边界检查
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                // 左上
                int row1 = (i-k>=0) ? (i-k) : 0;
                int col1 = (j-k>=0) ? (j-k) : 0;
                // 右下
                int row2 = (i+k<m) ? (i+k) : (m-1);
                int col2 = (j+k<n) ? (j+k) : (n-1);
                ans[i][j] = getOneArea(preSum, row1+1, col1+1, row2+1, col2+1);
            }
        }
        return ans;
    }
};
// @lc code=end

