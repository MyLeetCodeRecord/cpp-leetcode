/*
 * @lc app=leetcode.cn id=1247 lang=cpp
 *
 * [1247] 交换字符使得字符串相同
 */

// @lc code=start
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.size();
        int cntX = 0, cntY = 0;
        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]){
                if(s1[i] == 'x')
                    cntX++;
                else
                    cntY++;
            }
        }
        // 1. x和y都为奇数个 => (cntX+cntY)/2
        //      XX YY
        //      YY XX
        // 2. x和y都为偶数个 => (cntX-1)/2+(cntY-1)/2 + 2
        //      XX  X  YYYY  Y    =>    XX  YYYY  XY
        //      YY  Y  XXXX  X          YY  XXXX  YX
        if(cntX%2==0 && cntY%2==0)
            return cntX/2 + cntY/2;
        else if(cntX%2==1 && cntY%2==1)
            return (cntX-1)/2 + (cntY-1)/2 + 2;
        else
            return -1;

        // 或者理解为 => 奇数+奇数交换一次就变成了偶数+偶数
    }
};
// @lc code=end

