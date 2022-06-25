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
        for(int i=0; i<strs.size(); i++){   // Items
            int zeroNum = 0;
            int oneNum = 0;
            for(char ch: strs[i]){
                if(ch=='0')
                    zeroNum++;
                else
                    oneNum++;
            }
            // 没有先后顺序, 但是不能"分开"考虑
            for(int j=m; j>=zeroNum; j--){  // Capacity for 0
                for(int k=n; k>=oneNum; k--){   // Capacity for 1
                    dp[j][k] = max(dp[j][k], dp[j-zeroNum][k-oneNum]+1);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

