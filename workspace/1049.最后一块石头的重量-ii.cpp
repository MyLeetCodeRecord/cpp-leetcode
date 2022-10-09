/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
public:
    // 0-1背包
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(int n: stones)
            sum += n;
        int C = sum / 2;
        vector<int> dp(C+1, 0);
        // value[], weights[]都是stones[]
        for(int i=0; i<stones.size(); i++){
            for(int j=C; j>=stones[i]; j--){
                dp[j] = max(dp[j], dp[j-stones[i]]+stones[i]);
            }
        }
        // 注意这里不能用 2*C 代替sum
        return sum - 2*dp[C];
    }
};
// @lc code=end

