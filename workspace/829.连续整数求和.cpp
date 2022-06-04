/*
 * @lc app=leetcode.cn id=829 lang=cpp
 *
 * [829] 连续整数求和
 */

// @lc code=start
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0; 
        n *= 2;
        for (int k = 1; k * k < n; k++) {
            if (n % k != 0)
                continue;
            int a = n / k - k + 1;
            if (a % 2 == 0)
                ans++;
        }
        return ans;
    }
};
// @lc code=end

