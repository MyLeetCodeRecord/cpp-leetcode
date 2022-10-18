/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int ans = INT_MIN;
        int sum = 0;
        int left = 0;
        int right = 0;
        while(right < nums.size()){
            sum += nums[right++];
            if(right-left == k){
                ans = max(ans, sum);
                sum -= nums[left++];
            }
        }
        return (double)ans / (1.0 * k);
    }
};
// @lc code=end

