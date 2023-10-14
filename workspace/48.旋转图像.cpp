/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    // 方法二: 四个一组
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 圈数
        for(int i=0; i<n/2; i++){
            // 元素位置
            for(int j=0; j<(n+1)/2; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = tmp;
            }
        }
    }
    // 方法一: 一次水平 + 一次镜像
    // void updown(vector<vector<int> >& matrix) {    // 上下水平翻转
    //     int n = matrix.size();
    //     int tmp = 0;
    //     for(int j=0; j<n; j++){
    //         for(int i=0; i<n/2; i++){
    //             tmp = matrix[i][j];
    //             matrix[i][j] = matrix[n-i-1][j];
    //             matrix[n-i-1][j] = tmp;
    //         }
    //     }
    // }
    // void mirror(vector<vector<int> >& matrix) {    // 左上-右下对角线翻转
    //     int n = matrix.size();
    //     int tmp = 0;
    //     for(int r=0; r<n-1; r++){
    //         for(int c=r+1; c<n; c++){
    //             tmp = matrix[r][c];
    //             matrix[r][c] = matrix[c][r];
    //             matrix[c][r] = tmp;
    //         }
    //     }
    // }
    // void rotate(vector<vector<int>>& matrix) {
    //     // 1. 上下翻转
    //     updown(matrix);
    //     // 2. 对角线镜像翻转
    //     mirror(matrix);
    // }
};
// @lc code=end

