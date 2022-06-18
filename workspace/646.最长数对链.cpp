/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */

// @lc code=start
class Solution {
public:
    // 按结束时间排序
    static bool cmp(vector<int>& l, vector<int>& r){
        return l[1] < r[1];
    }
    // LC300. Longest LIS的变形, 体会一下最长递增子序列的本质
    int findLongestChain(vector<vector<int>>& pairs) {
        int ans = 1;
        sort(pairs.begin(), pairs.end());
        // dp[i]: 严格以pairs[i]结尾的最长序列长度
        vector<int> dp(pairs.size(), 1);
        for(int i=1; i<pairs.size(); i++){
            for(int j=0; j<i; j++){
                if(pairs[i][0] > pairs[j][1]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end

