/*
 * @lc app=leetcode.cn id=1301 lang=cpp
 *
 * [1301] 最大得分的路径数目
 */

// @lc code=start
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));  // 最大路径和
        vector<vector<int> > methods(m, vector<int>(n, 0)); // 最大值的路径数目
        dp[0][0] = 0;
        methods[0][0] = 1;
        for(int i=1; i<m; i++){
            if(board[i][0] == 'X')
                break;
            dp[i][0] = dp[i-1][0] + (board[i][0]-'0');
            methods[i][0] = 1;
        }
        for(int j=1; j<n; j++){
            if(board[0][j] == 'X')
                break;
            dp[0][j] = dp[0][j-1] + (board[0][j]-'0');
            methods[0][j] = 1;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(board[i][j] == 'X')
                    continue;
                dp[i][j] = max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1]));
                // 三个方向都不行
                if(dp[i][j]==0 && board[i][j]!='S')
                    continue;
                if(dp[i-1][j-1]==dp[i][j])
                    methods[i][j] += methods[i-1][j-1];
                if(dp[i-1][j]==dp[i][j])
                    methods[i][j] += methods[i-1][j];
                if(dp[i][j-1]==dp[i][j])
                    methods[i][j] += methods[i][j-1];
                // 跳过end='S'的最大值计算
                if(i==m-1 && j==n-1)
                    continue;
                dp[i][j] += (board[i][j]-'0');
                dp[i][j] %= 1000000007;
                methods[i][j] %= 1000000007;
            }
        }
        return {dp[m-1][n-1]%1000000007, methods[m-1][n-1]%1000000007};
    }
};
// @lc code=end
