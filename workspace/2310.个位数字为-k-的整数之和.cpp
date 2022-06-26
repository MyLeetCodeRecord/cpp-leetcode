/*
 * @lc app=leetcode.cn id=2310 lang=cpp
 *
 * [2310] 个位数字为 K 的整数之和
 */

// @lc code=start
class Solution {
public:
    // 可以重复包含同一个整数 => 完全背包
    int minimumNumbers(int num, int k) {
        // dp[j]: 由kSet中元素构成的和为j的集合的最小长度
        vector<int> dp(num+1, INT_MAX);
        vector<int> kSet;
        int tmp = k;
        while(tmp <= num){
            kSet.push_back(tmp);
            tmp+=10;
        }
        dp[0] = 0;
        for(int i=0; i<kSet.size(); i++){
            for(int j=kSet[i]; j<=num; j++){
                if(dp[j-kSet[i]]<INT_MAX)
                    dp[j] = min(dp[j], dp[j-kSet[i]]+1);
            }
        }
        return (dp[num]==INT_MAX) ? -1 : dp[num];
    }
};
// @lc code=end

