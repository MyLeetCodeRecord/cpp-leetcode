/*
 * @lc app=leetcode.cn id=1208 lang=cpp
 *
 * [1208] 尽可能使字符串相等
 */

// @lc code=start
class Solution {
public:
    // s和t是对齐的两个字符串, 所以一个滑动窗口, 控制窗口内不同的字符差值不超过maxCost即可
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0;
        int right = 0;
        int ans = 0;
        while(right<s.size()){
            // 扩大右窗口
            maxCost -= abs(s[right] - t[right]);    // 如果不同, 花费一个cost
            right++;
            // 收缩左窗口
            while(maxCost < 0){
                maxCost += abs(s[left] - t[left]); // 释放一个cost
                left++;
            }
            ans = max(ans, right-left);
        }
        return ans;
    }
};
// @lc code=end

