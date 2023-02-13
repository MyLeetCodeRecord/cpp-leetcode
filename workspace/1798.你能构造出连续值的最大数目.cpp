/*
 * @lc app=leetcode.cn id=1798 lang=cpp
 *
 * [1798] 你能构造出连续值的最大数目
 */

// @lc code=start
class Solution {
public:
    // 为了构造「连续」整数, coins应该从小开始取
    // 灵神题解: https://leetcode.cn/problems/maximum-number-of-consecutive-values-you-can-make/solution/mei-xiang-ming-bai-yi-zhang-tu-miao-dong-7xlx/
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int ans = 0;
        for(int c : coins){
            if(c > ans + 1)
                return ans+1;
            ans += c;
        }
        return ans+1;   // 返回值为个数, 而不是最大值
    }
};
// @lc code=end

