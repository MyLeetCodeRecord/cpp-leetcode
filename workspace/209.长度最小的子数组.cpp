/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int left = 0;
        int right = 0;
        int sum = 0;
        while(right < nums.size()){
            sum += nums[right++];
            while(sum >= target){
                ans = min(ans, right-left);
                sum -= nums[left++];
            }
        }
        return ans==INT_MAX ? 0 : ans;
    }
};
// @lc code=end

