/*
 * @lc app=leetcode.cn id=1784 lang=cpp
 *
 * [1784] 检查二进制字符串字段
 */

// @lc code=start
class Solution {
public:
    // "判断字符串是不是由左边连续的1和右边连续的0组成"
    bool checkOnesSegment(string s) {
        int l=0, r=s.size()-1;
        while(s[l]=='1')
            l++;
        while(s[r]=='0')
            r--;
        return l-r==1;  // l要领先r一个位置
    }
};
// @lc code=end

