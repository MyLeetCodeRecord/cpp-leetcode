/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */

// @lc code=start
class Solution {
public:
    bool isLongPressedName(string s, string t) {
        int m = s.size();
        int n = t.size();
        int i=0, j=0;
        while(i < m){
            // 遇到不相等, 或者字符串t提前结束 => false
            if(j==n || s[i]!=t[j])
                return false;
            // 找s[i]和t[j]连续次数, 保证在t中次数大于等于在s中的次数
            int ii = i;
            while(ii<m && s[ii]==s[i])
                ii++;
            int cnt_i = ii-i+1;
            int jj = j;
            while(jj<n && t[jj]==t[j])
                jj++;
            int cnt_j = jj-j+1;
            if(cnt_j < cnt_i)
                return false;
            // 移动指针
            i = ii;
            j = jj;
        }
        return (i==m) && (j==n);
    }
};
// @lc code=end

