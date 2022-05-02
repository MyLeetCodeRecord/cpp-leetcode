/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
 */

// @lc code=start
class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int bit = 0;        // 记录当前bit是第几位
        int preOne = -1;    // 记录上一个 1 出现的位置
        while(n != 0){
            int cur = n & 1;
            if(cur == 1){
                if(preOne != -1){
                    ans = max(ans, bit-preOne);
                }
                preOne = bit;
            }
            n = n >> 1;
            bit++;
        }
        return ans;
    }
};
// @lc code=end

