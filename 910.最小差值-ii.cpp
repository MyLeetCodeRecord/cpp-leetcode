/*
 * @lc app=leetcode.cn id=910 lang=cpp
 *
 * [910] 最小差值 II
 */

// @lc code=start
class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = nums.back() - nums[0];
        for(int i=0; i<nums.size()-1; i++){
            int b = nums[i]+k;
            int c = nums[i+1]-k;
            int minVal = min(nums[0]+k, nums[i+1]-k);
            int maxVal = max(nums.back()-k, nums[i]+k);
            ans = min(ans, maxVal-minVal);
        }
        return ans;
    }
};
// @lc code=end

