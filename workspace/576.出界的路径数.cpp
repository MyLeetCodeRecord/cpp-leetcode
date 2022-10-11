/*
 * @lc app=leetcode.cn id=576 lang=cpp
 *
 * [576] 出界的路径数
 */

// @lc code=start
class Solution {
private:
    int directions[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    int getIndex(int x, int y, int n){
        return x*n + y;
    }
    vector<int> parseIndex(int index, int n){
        return {index/n, index%n};
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // dp[index][move]: 从index=(x*n+y)出发, 最多move步能够到达边缘的路径数
        vector<vector<int> > dp(m*n, vector<int>(maxMove+1, 0));

        // 初始化, 注意这里是对所有临界pos的dp值"+1",而不是"=1"
        for(int move=1; move<=maxMove; move++){
            for(int x=0; x<m; x++){
                dp[getIndex(x, 0, n)][move] += 1;
                dp[getIndex(x, n-1, n)][move] += 1;
            }
            for(int y=0; y<n; y++){
                dp[getIndex(0, y, n)][move] += 1;
                dp[getIndex(m-1, y, n)][move] += 1;
            }
        }
        // 状态转移
        for(int move=1; move<=maxMove; move++){
            // 状态转移第二维只使用上一轮的[move-1], 所以idx顺序(或者展开成(x,y))不重要
            for(int idx=0; idx<m*n; idx++){
                int x = parseIndex(idx, n)[0];
                int y = parseIndex(idx, n)[1];
                for(int d=0; d<4; d++){
                    int nextX = x+directions[d][0];
                    int nextY = y+directions[d][1];
                    // 这里不要把边界线上的位置排除掉, 因为可以重复访问, 只是限制了步数maxMove
                    if(nextX>=0 && nextX<m && nextY>=0 && nextY<n){
                        dp[idx][move] += dp[getIndex(nextX, nextY, n)][move-1];
                        dp[idx][move] %= 1000000007;
                    }
                }
            }
        }
        return dp[getIndex(startRow, startColumn, n)][maxMove];
    }
};
// @lc code=end

