/*
 * @lc app=leetcode.cn id=1438 lang=cpp
 *
 * [1438] 绝对差不超过限制的最长连续子数组
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // 这里用有序map也可以
        // 最大最小分别是rbegin()->first & begin()->first, 但要记得额外erase
        multiset<int> st;
        int n = nums.size();
        int ans = 0;
        int l = 0, r = 0;
        while(r < n){
            st.insert(nums[r++]);
            while(*st.rbegin()-*st.begin() > limit){
                st.erase(st.find(nums[l++]));
            }
            ans = max(ans, r-l);
        }
        return ans;
    }
};
// @lc code=end

