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
        int n = nums.size();
        int all = 0;
        for(int i=0; i<n; i++){
            all += nums[i];
        }
        int target = all - x;
        int ans = -1;
        int l = 0, r = 0;
        int sum = 0;
        while(r < n){
            // 扩大右边界
            sum += nums[r++];
            // 收缩左边界
            while(l<r && sum>target){
                sum -= nums[l++];
            }
            // 找到「和=target」的最长的连续子数组
            if(sum == target)
                ans = max(ans, r-l);
        }
        return (ans==-1) ? -1 : (n-ans);
    }
};
// @lc code=end

