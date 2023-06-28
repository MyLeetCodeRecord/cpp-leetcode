/*
 * @lc app=leetcode.cn id=1758 lang=cpp
 *
 * [1758] 生成交替二进制字符串的最少操作数
 */

// @lc code=start

// 交替字符串只能为 "0101.." 或 "1010..", 分别计算将 s 变成这两种情况所需要的操作数, 取最小值
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            int cur = i & 1;
            int bit = (s[i]-'0') & 1;
            if(cur != bit)
                cnt++;
        }
        return min(cnt, n-cnt);
    }
};
// @lc code=end

