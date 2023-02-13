/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = g.size()-1;
        int j = s.size()-1;
        while(i>=0 && j>=0){
            if(g[i] <= s[j])
                j--;
            i--;
        }
        return s.size() - 1 - j;
    }
};
// @lc code=end

