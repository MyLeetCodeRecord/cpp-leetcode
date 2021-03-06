/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */
// @lc code=start
class Solution {
public:
    // DFS从边缘O开始, 所有边缘O出发的O都要区分开, 标成A
    void DFS(vector<vector<char> > & board, int row, int col) {
        // 递归终点
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size())
            return ;
        if(board[row][col] != 'O')
            return ;
        board[row][col] = 'A';
        DFS(board, row-1, col);
        DFS(board, row+1, col);
        DFS(board, row, col-1);
        DFS(board, row, col+1);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        // 边缘出发的连续O block不需要改为X, 因此暂时标记为A
        for(int i=0; i<m; i++){
            if(board[i][0] == 'O')
                DFS(board, i, 0);
            if(board[i][n-1] == 'O')
                DFS(board, i, n-1);
        }
        for(int j=0; j<n; j++){
            if(board[0][j] == 'O')
                DFS(board, 0, j);
            if(board[m-1][j] == 'O')
                DFS(board, m-1, j);
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';  // 内部O全部标记为X
                else if(board[i][j] == 'A')
                    board[i][j] = 'O';  // 边缘O全部还原为O
            }
        }
    }
};
// @lc code=end
