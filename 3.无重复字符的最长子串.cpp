/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int ans = 0;
        int left = 0;
        int right = 0;
        while(right < s.size()){
            // 扩大右窗口
            st.insert(s[right++]);
            // 缩小左窗口
            while(st.find(s[right])!=st.end()){
                st.erase(s[left++]);
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};
// @lc code=end

