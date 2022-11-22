/*
 * @lc app=leetcode.cn id=878 lang=cpp
 *
 * [878] 第 N 个神奇数字
 */

// @lc code=start
class Solution {
public:
    typedef long long LL;

    int gcd(int a, int b){
        if(a % b == 0)
            return b;
        return gcd(b, a % b);   // "%"而不是"-"
    }
    int nthMagicalNumber(int n, int a, int b) {
        // [大上周周赛]最小公倍数 = a*b/gcd(a,b)
        LL lcm_ab = a / gcd(max(a, b), min(a, b)) * b;
        // yxc出的题吗...
        // 容斥原理求 x 范围内的神奇数个数
        //     => 能被 a 或 b 整除 = 被 a 整除 + 被 b 整除 - 既能被 a 又能被 b 整除
        //     => x 中被 a 整除的正整数 = x // a

        // "第n个" --> 二分查找(target不唯一, 找左边界)
        LL l = min(a, b);
        LL r = (LL) n * min(a, b);
        while(l < r){
            LL mid = (l+r)/2;
            LL magic = mid/a + mid/b - mid/lcm_ab;  // 容斥原理
            if (magic < n)
                l = mid+1;
            else
                r = mid;
        }
        return l % 1000000007;
    }
};
// @lc code=end

