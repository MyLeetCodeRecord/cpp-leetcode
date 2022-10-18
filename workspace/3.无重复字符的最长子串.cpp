/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int ans = 0;
        int left = 0;
        for(int right=0; right < s.size(); right++){
            // 扩大右窗口
            mp[s[right]]++;
            // 缩小左窗口
            while(mp.find(s[right])!=mp.end() && mp[s[right]] > 1){
                mp[s[left++]]--;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};
// @lc code=end

