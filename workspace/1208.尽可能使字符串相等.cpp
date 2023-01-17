/*
 * @lc app=leetcode.cn id=1208 lang=cpp
 *
 * [1208] 尽可能使字符串相等
 */

// @lc code=start
class Solution {
public:
    // 滑动窗口: 控制窗口内不同的字符差值不超过maxCost即可
    int equalSubstring(string s, string t, int maxCost) {
        int m = s.size();
        int n = t.size();
        int ans = 0;
        int l=0, r=0;
        int cost = 0;
        while(r < n){
            cost += abs(s[r]-t[r++]);
            while(cost > maxCost){
                cost -= abs(s[l]-t[l++]);
            }
            // 长度为r-l+1, 删除一个元素后长度为r-l
            ans = max(ans, r-l);
        }
        return ans;
    }
};
// @lc code=end

