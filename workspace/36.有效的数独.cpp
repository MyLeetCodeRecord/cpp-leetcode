/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // hash表: 最后一维为 1~9
        int rows[9][9];
        int columns[9][9];
        int areas[3][3][9];
        // 用 0 填充
        memset(rows,0,sizeof(rows));
        memset(columns,0,sizeof(columns));
        memset(areas,0,sizeof(areas));
        // 遍历数独表, 更新3个hash表
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    int index = c - '0' - 1;
                    rows[i][index]++;               // 行
                    columns[j][index]++;            // 列
                    areas[i / 3][j / 3][index]++;   // 区域
                    // 只需要判断“当前”, 不需要"瞻前顾后"
                    if (rows[i][index] > 1 || columns[j][index] > 1 || areas[i / 3][j / 3][index] > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

