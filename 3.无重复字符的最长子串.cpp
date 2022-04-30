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
        int right = 1;
        while(right < s.size()){
            if(st.find(s[right]) == st.end()){
                right++;
                st.insert(s[right]);
                continue;
            }
            while(s[left]!=s[right]){
                left++;
                st.erase(s[left]);
            }
            ans = max(ans, right-left);
        }
        return ans;
    }
};
// @lc code=end

