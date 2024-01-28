/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(char ch: s){
            mp[ch]++;
        }
        bool odd = false;
        int ans = 0;
        for(auto &[k, v] : mp){
            if(v & 1)
                odd = true;
            ans += v/2*2;
        }
        return ans + odd;
    }
};
// @lc code=end

