/*
 * @lc app=leetcode.cn id=1493 lang=cpp
 *
 * [1493] 删掉一个元素以后全为 1 的最长子数组
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int zeroCnt = 0;
        for(int l=0, r=0; r<n; r++){
            zeroCnt += (nums[r]==0);
            while(zeroCnt > 1){
                zeroCnt -= (nums[l++]==0);
            }
            ans = max(ans, r-l);
        }
        return ans;
    }
};
// @lc code=end

