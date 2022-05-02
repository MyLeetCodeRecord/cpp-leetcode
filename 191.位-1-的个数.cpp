/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    uint32_t lowbit(uint32_t x) {
        return x & (-x);
    }
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n!=0){
            n -= lowbit(n);
            cnt++;
        }
        return cnt;
    }
};
// @lc code=end

