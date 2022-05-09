/*
 * @lc app=leetcode.cn id=942 lang=cpp
 *
 * [942] 增减字符串匹配
 */

// @lc code=start
class Solution {
public:
    // 贪心
    vector<int> diStringMatch(string s) {
        vector<int> ans(s.size()+1, 0);
        int curMin = 0;
        int curMax = s.size();
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'I'){
                ans[i] = curMin++;
            }
            else{
                ans[i] = curMax--;
            }
        }
        // 剩下一个位置(ans比s多一个元素)
        ans[s.size()] = curMin;
        return ans;
    }
};
// @lc code=end

https://leetcode.cn/problems/di-string-match/