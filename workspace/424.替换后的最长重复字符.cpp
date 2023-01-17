/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */

// @lc code=start
class Solution {
public:
    bool check(unordered_map<char, int>& mp, int limit){
        if(mp.size()==1)
            return true;
        int sumV = 0, maxV = 0;
        for(auto &[k, v] : mp){
            maxV = max(maxV, v);
            sumV += v;
        }
        return (sumV - maxV) <= limit;
    }
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        unordered_map<char, int> mp;
        int l = 0, r = 0;
        while(r < n){
            mp[s[r++]]++;
            while(check(mp, k)==false){
                mp[s[l++]]--;
            }
            ans = max(ans, r-l);
        }
        return ans;
    }
};
// @lc code=end

