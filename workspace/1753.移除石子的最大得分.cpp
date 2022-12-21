/*
 * @lc app=leetcode.cn id=1753 lang=cpp
 *
 * [1753] 移除石子的最大得分
 */

// @lc code=start
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int stones[3] = {a, b, c};
        sort(stones, stones+3);
        // c更大或等于a+b, 则答案为a+b次
        if(stones[2] >= stones[0]+stones[1])
            return stones[0]+stones[1];
        // a+b>c => 交替取a, b中更大的一个
        // c每次与a,b中更大的匹配, 保证a和b之间的差距尽可能小, 最后可执行(a+b-c)/2次操作
        else
            return (stones[0]+stones[1]-stones[2])/2 + stones[2];
    }
};
// @lc code=end

