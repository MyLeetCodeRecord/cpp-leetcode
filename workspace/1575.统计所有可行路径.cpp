/*
 * @lc app=leetcode.cn id=1575 lang=cpp
 *
 * [1575] 统计所有可行路径
 */

// @lc code=start
class Solution {
    int mod = 1000000007;
public:
    // 4个params, 只有start, fuel是变化的, 所以用二维dp来表示这两个可变参数
    // dp[i][j]: 从位置i出发, 当前油量为j时, 到达目的地的路径数
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();

        // f[i][j]: 从位置 i 出发, 当前油量为 j 时, 到达目的地的路径数
        vector<vector<int> > dp(n, vector<int>(fuel+1, 0));
        
        // 对于本身位置就在目的地的状态, 路径数为 1
        for (int i = 0; i <= fuel; i++)
            dp[finish][i] = 1;

        // 从状态转移方程可以发现 f[i][fuel]=f[i][fuel]+f[k][fuel-need]
        // 在计算 f[i][fuel] 的时候依赖于 f[k][fuel-need]
        // 其中 i 和 k 并无严格的大小关系
        // 而 fuel 和 fuel-need 具有严格大小关系: fuel >= fuel-need
        // 因此需要先从小到大枚举油量
        for(int cur = 0; cur <= fuel; cur++){
            for(int i = 0; i < n; i++){
                for(int k = 0; k < n; k++){
                    if(i != k){
                        int need = abs(locations[i] - locations[k]);
                        if(cur >= need){
                            dp[i][cur] += dp[k][cur-need];
                            dp[i][cur] %= mod;
                        }
                    }
                }
            }
        }
        return dp[start][fuel];
    }
};
// @lc code=end

