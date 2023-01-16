/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 *
 * [1456] 定长子串中元音的最大数目
 */

// @lc code=start
class Solution {
public:
    unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
    int maxVowels(string s, int k) {
        int n = s.size();
        int cnt = 0;
        for(int i=0; i<k; i++){
            if(st.find(s[i])!=st.end())
                cnt++;
        }
        int ans = cnt;
        for(int i=k; i<n; i++){
            cnt += (st.find(s[i])!=st.end());
            cnt -= (st.find(s[i-k])!=st.end());
            ans = max(ans, cnt);
        }
        return ans;
    }
};
// @lc code=end

