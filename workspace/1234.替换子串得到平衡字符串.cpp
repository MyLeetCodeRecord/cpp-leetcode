/*
 * @lc app=leetcode.cn id=1234 lang=cpp
 *
 * [1234] 替换子串得到平衡字符串
 */

// @lc code=start
class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        int m = n/4;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }
        if(mp['Q']==m && mp['W']==m && mp['E']==m && mp['R']==m)
            return 0;
        // 同向双指针: 目标是找「要替换的子串」, 子串要满足「令剩余子串每个字符数量<=m」的要求
        int l = 0, r = 0;
        int ans = n;
        while(r < n){
            mp[s[r++]]--;
            while(mp['Q']<=m && mp['W']<=m && mp['E']<=m && mp['R']<=m){
                ans = min(ans, r-l);
                mp[s[l++]]++;
            }
        }
        return ans;
    }
};
// @lc code=end

