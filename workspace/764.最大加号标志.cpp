/*
 * @lc app=leetcode.cn id=764 lang=cpp
 *
 * [764] 最大加号标志
 */

// @lc code=start
class Solution {
public:
    /* 直线用dp[N]能求！=> 两条垂直直线也能求!
     * 基础做法 - 4个dp: ans = min(dp_up[i][j], dp_down[i][j], dp_left[i][j], dp_right[i][j])
     */
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));
        for (auto mine : mines) {
            int x = mine[0], y = mine[1];
            grid[x][y] = 0;
        }
        vector<vector<int>> dp_down(n, vector<int>(n, 0));
        vector<vector<int>> dp_up(n, vector<int>(n, 0));
        vector<vector<int>> dp_right(n, vector<int>(n, 0));
        vector<vector<int>> dp_left(n, vector<int>(n, 0));
        for(int j=0; j<n; j++){
            dp_up[0][j] = grid[0][j];
            for(int i=1; i<n; i++){
                if(grid[i][j] == 0)
                    dp_up[i][j] = 0;
                else
                    dp_up[i][j] = dp_up[i-1][j] + 1;
            }
            dp_down[n-1][j] = grid[n-1][j];
            for(int i=n-2; i>=0; i--){
                if(grid[i][j] == 0)
                    dp_down[i][j] = 0;
                else
                    dp_down[i][j] = dp_down[i+1][j] + 1;
            }
        }
        for(int i=0; i<n; i++){
            dp_left[i][0] = grid[i][0];
            for(int j=1; j<n; j++){
                if(grid[i][j]==0)
                    dp_left[i][j] = 0;
                else
                    dp_left[i][j] = dp_left[i][j-1]+1;
            }
            dp_right[i][n-1] = grid[i][n-1];
            for(int j=n-2; j>=0; j--){
                if(grid[i][j]==0)
                    dp_right[i][j] = 0;
                else
                    dp_right[i][j] = dp_right[i][j+1]+1;
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int cnt = min({dp_left[i][j], dp_right[i][j], dp_up[i][j], dp_down[i][j]});
                res = max(res, cnt);
            }
        } 
        return res;
    }
};
// @lc code=end

