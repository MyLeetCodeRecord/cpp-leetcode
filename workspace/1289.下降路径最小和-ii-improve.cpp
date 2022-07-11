/*
 * @lc app=leetcode.cn id=1289 lang=cpp
 *
 * [1289] 下降路径最小和  II
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        // 有限变量替代二维dp数组
        int first_sum = 0;
        int first_pos = -1;
        int second_sum = 0;
        for(int i=0; i<n; i++){
            int layer_first_sum = INT_MAX;
            int layer_first_pos = -1;
            int layer_second_sum = INT_MAX;
            for(int j=0; j<n; j++){
                // 仅当j==firstPos时使用secondSum
                int curPathSum = ((j!=first_pos) ? first_sum : second_sum) + grid[i][j];
                // 遇到最小 => 更新最小和次小
                if(curPathSum < layer_first_sum){
                    layer_second_sum = layer_first_sum;
                    layer_first_sum = curPathSum;
                    layer_first_pos = j;
                }
                // 遇到次小 => 更新次小
                else if(curPathSum < layer_second_sum){
                    layer_second_sum = curPathSum;
                }
            }
            first_sum = layer_first_sum;
            first_pos = layer_first_pos;
            second_sum = layer_second_sum;
        }
        return first_sum;
    }
};
// @lc code=end

