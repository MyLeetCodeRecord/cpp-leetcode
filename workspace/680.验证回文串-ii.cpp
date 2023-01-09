/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文串 II
 */

// @lc code=start
class Solution {
public:
    bool standardPalindrome(string s){
        int n = s.size();
        for(int i=0; i<n/2; i++){
            if(s[i]!=s[n-i-1])
                return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        for(int i=0; i<n/2; i++){
            if(s[i]!=s[n-i-1]){
                string first = s.substr(0, i) + s.substr(i+1);
                string second = s.substr(0, n-i-1) + s.substr(n-i);
                return standardPalindrome(first) || standardPalindrome(second);
            }
        }
        return true;    // 没有不相等字符对的情况
    }
};
// @lc code=end

