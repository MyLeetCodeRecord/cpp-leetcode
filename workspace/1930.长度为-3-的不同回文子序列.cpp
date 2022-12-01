/*
 * @lc app=leetcode.cn id=1930 lang=cpp
 *
 * [1930] 长度为 3 的不同回文子序列
 */

// @lc code=start
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> firstOccur(26, n);
        vector<int> lastOccur(26, -1);
        for(int i=0; i<n; i++){
            if(firstOccur[s[i]-'a'] == n)
                firstOccur[s[i]-'a'] = i;
            lastOccur[s[i]-'a'] = i;
        }
        int ans = 0;
        for(int i=0; i<26; i++){
            int l = firstOccur[i];
            int r = lastOccur[i];
            if(r-l < 2)
                continue;
            unordered_set<char> st;
            for(int a=l+1; a<r; a++){
                st.insert(s[a]);
            }
            ans += st.size();
        }
        return ans;
    }
};
// @lc code=end

