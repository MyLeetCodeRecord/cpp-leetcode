/*
 * @lc app=leetcode.cn id=1358 lang=cpp
 *
 * [1358] 包含所有三种字符的子字符串数目
 */

// @lc code=start
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        int l = 0, r = 0;
        int cntA = 0, cntB = 0, cntC = 0;
        while(r < n){
            cntA += (s[r]=='a');
            cntB += (s[r]=='b');
            cntC += (s[r]=='c');
            r++;
            while(cntA>0 && cntB>0 && cntC>0){
                cntA -= (s[l]=='a');
                cntB -= (s[l]=='b');
                cntC -= (s[l]=='c');
                l++;
            }
            ans += l;
        }
        return ans;
    }
};
// @lc code=end

