/*
 * @lc app=leetcode.cn id=1695 lang=cpp
 *
 * [1695] 删除子数组的最大得分
 */

// @lc code=start
class Solution {
public:
    // 正整数数组nums, 求累加和最大的无重复元素的连续子数组, 返回其累加和的值。
    // 和LC3. 无重复的最长字符串类似, 用map, set都可以, 还是map省事...
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> mp;
        int sum = 0;
        int left = 0;
        int right = 0;
        while(right < nums.size()){
            while(left<right && mp.find(nums[right])!=mp.end() && mp[nums[right]] != 0){
                sum -= nums[left];
                mp[nums[left++]]--;
            }
            mp[nums[right]]++;
            sum += nums[right++];
            ans = max(ans, sum);
        }
        return ans;
    }
};
// @lc code=end

