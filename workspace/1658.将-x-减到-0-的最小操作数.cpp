/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

// @lc code=start
class Solution {
public:
    // 逆向思维转化为lc209
    int minOperations(vector<int>& nums, int x) {
        int target = 0;
        for(int i=0; i<nums.size(); i++)
            target += nums[i];
        target -= x;
        // 找到「和=target」的最长的连续子数组
        int ans = -1;
        int sum = 0;
        for(int l=0, r=0; r<nums.size(); r++){
            // 扩大右边界
            sum += nums[r];
            // 缩小左边界
            while(l<=r && sum>target){
                sum -= nums[l++];
            }
            if(sum == target)
                ans = max(ans, r-l+1);
        }
        return (ans==-1) ? -1 : nums.size()-ans;
    }
};
// @lc code=end

