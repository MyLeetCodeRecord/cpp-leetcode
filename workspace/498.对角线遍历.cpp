/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 */

// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result;
        /* 矩阵中元素个数 */
        int all = mat.size() * mat[0].size(); 
        /* 遍历矩阵的x行，y列 */
        int x = 0, y = 0;
        /* 开始遍历 */
        for (int i = 0; i < all; i++) {
            /* 将数据存储到vector中 */
            result.push_back(mat[x][y]);
            // 右上
            if ((x+y)%2 == 0) {
                if (y == mat[0].size() - 1)
                    x++; // 如果是最后一列，不能再修改列数y了，会越界
                else if (x == 0)
                    y++; // 如果是第一行，向右即可
                else{
                    x--;
                    y++; // 正常右上
                }
            }
            // 左下
            else {
                if (x == mat.size() - 1)
                    y++; //如果是最后一行，不能再修改行数x了，会越界
                else if (y == 0) 
                    x++; //如果是第一列，向下即可
                else{
                    x++;
                    y--; //正常左下
                }
            }
        }
        return result;
    }
};
// @lc code=end

