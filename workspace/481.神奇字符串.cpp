/*
 * @lc app=leetcode.cn id=481 lang=cpp
 *
 * [481] 神奇字符串
 */

// @lc code=start
class Solution {
public:
    int magicalString(int n) {
        string ans = "122";
        int idx = 2;
        int i = 3;
        int cnt = 1;
        bool one = true;
        while(i < n){
            int nxt = ans[idx]-'0';
            for(int a=0; a<nxt; a++)
                ans += (one ? '1' : '2');
            if(one)
                cnt += nxt;
            i += nxt;
            idx++;
            one = !one;
        }
        // 减去结尾多count的1
        if(!one){
            cnt -= (i-n);
        }
        return cnt;
    }
};
// @lc code=end

