/*
 * @lc app=leetcode.cn id=1790 lang=cpp
 *
 * [1790] 仅执行一次字符串交换能否使两个字符串相等
 */

// @lc code=start
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> diff;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i]){
                diff.push_back(i);
            }
        }
        if(diff.size() == 0)
            return true;
        if(diff.size() == 2 && s1[diff[0]]==s2[diff[1]] && s1[diff[1]]==s2[diff[0]])
            return true;
        return false;
    }
};
// @lc code=end

