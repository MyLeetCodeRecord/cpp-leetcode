/*
 * @lc app=leetcode.cn id=764 lang=cpp
 *
 * [764] 最大加号标志
 */

// @lc code=start
class Solution {
public:
    /* 直线用dp[N]能求！=> 两条垂直直线也能求!
     * 基础做法: ans = min(dp_up[i][j], dp_down[i][j], dp_left[i][j], dp_right[i][j])
     * 进一步: 可以压缩到一个三层for循环中, 外层的 k 表示行/列, 内层的 i 和 j分别从两个端点出发, 4个方向的计算互不影响
     */
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        // 记录棋盘 0/1 的位置
        vector<vector<int>> grid(n, vector<int>(n, 1));
        for(auto mine : mines) {
            int x = mine[0], y = mine[1];
            grid[x][y] = 0;
        }
        // 可以覆盖写到grid上, 但是何必呢...
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for(int k=0; k<n; k++){
            // 这个时候不能用dp_left[i-1][j]这类值来更新了, 
            // 但计算的单向性决定, 可以用4个方向的变量来代替dp_dir[][]记录该方向上连续了多少个1
            int left = 0, right = 0;
            int up = 0, down = 0;
            // 对每个点更新4次min, 得到的就是"+"的最大范围了
            for(int i=0, j=n-1; i<n && j>=0; i++, j--){
                // 第k行, i从左出发, j从右出发
                left = (grid[k][i]==0) ? 0 : left+1;
                dp[k][i] = min(dp[k][i], left);
                right = (grid[k][j]==0) ? 0: right+1;
                dp[k][j] = min(dp[k][j], right);
                // 第k列, i从上出发, j从下出发
                up = (grid[i][k]==0) ? 0 : up+1;
                dp[i][k] = min(dp[i][k], up);
                down = (grid[j][k]==0) ? 0 : down+1;
                dp[j][k] = min(dp[j][k], down);
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
// @lc code=end

