/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> mp;
        int ans = 0;    // 注意s长度可能为0
        for(int l=0, r=0; r<s.size(); r++){
            // 扩大右窗口
            mp[s[r]]++;
            // 缩小左窗口
            while(mp[s[r]] > 1){
                mp[s[l++]]--;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
// @lc code=end

