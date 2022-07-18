/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int ans = 1;
        vector<int> dp(nums.size(), 1);
        vector<int> cnt(nums.size(), 1);    // 注意cnt[i]记录的是严格以i结尾的LIS长度对应的序列数
        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if(dp[j]+1 == dp[i]){
                        cnt[i] += cnt[j];
                    }
                }
            }
        }
        // cnt[i]最大值并非最终ans, 而是要找所有dp[i]==maxLen的cnt[i]之和
        int maxLen = 0;
        for(int i=0; i<nums.size(); i++){
            if(dp[i] > maxLen){
                ans = cnt[i];
                maxLen = dp[i];
            }
            else if(dp[i] == maxLen){
                ans += cnt[i];
            }
        }
        return ans;
    }
};
// @lc code=end

