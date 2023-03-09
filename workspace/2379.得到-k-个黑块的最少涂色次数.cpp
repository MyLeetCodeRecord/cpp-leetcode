/*
 * @lc app=leetcode.cn id=2379 lang=cpp
 *
 * [2379] 得到 K 个黑块的最少涂色次数
 */

// @lc code=start
class Solution {
public:
    // 固定尺寸的滑动窗口
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int l=0, r=n-1;
        int blackCnt = 0;
        for(int i=0; i<k; i++){
            blackCnt += (blocks[i]=='B');
        }
        int ans = k - blackCnt;
        for(int i=k; i<n; i++){
            blackCnt -= (blocks[i-k]=='B');
            blackCnt += (blocks[i]=='B');
            ans = min(ans, k-blackCnt);
        }
        return ans;
    }
};
// @lc code=end

