/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
public:
    // dp[j][k]: j个0和k个1的最大子集size
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        for(int i=0; i<strs.size(); i++){   // Item
            int zeroNum = 0;
            int oneNum = 0;
            for(char ch: strs[i]){
                if(ch=='0')
                    zeroNum++;
                else
                    oneNum++;
            }
            for(int j=m; j>=zeroNum; j--){  // Capacity
                for(int k=n; k>=oneNum; k--){   // Capacity
                    dp[j][k] = max(dp[j][k], dp[j-zeroNum][k-oneNum]+1);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

