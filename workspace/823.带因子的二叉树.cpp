/*
 * @lc app=leetcode.cn id=823 lang=cpp
 *
 * [823] 带因子的二叉树
 */

// @lc code=start
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[arr[i]] = i;
        }
        int ans = 0, MOD = 1e9+7;
        vector<long long> dp(n, 1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[i]%arr[j]==0 && mp.find(arr[i]/arr[j]) != mp.end()){
                    // leftChild = arr[j], rightChild = arr[i]/arr[j]
                    // arr[j]和arr[i]/arr[j]的方案数已经求过了, 且两棵子树互不影响, 直接用两个dp值相乘
                    dp[i] += (dp[j] * dp[mp[arr[i]/arr[j]]]) % MOD;
                }
            }
            ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};
// @lc code=end

