/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 */

// @lc code=start
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // 先排序 => 新加入的元素能够加入子集当且仅当能整除子集内最大的数
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        vector<int> pre(nums.size(), -1);
        int maxLen = 1;
        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j]==0){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j]+1;
                        pre[i] = j;
                    }
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        vector<int> ans;
        for(int i=nums.size()-1; i>=0; i--){
            if(dp[i]==maxLen){
                while(i!=-1){
                    ans.push_back(nums[i]);
                    i = pre[i];
                }
                break;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

