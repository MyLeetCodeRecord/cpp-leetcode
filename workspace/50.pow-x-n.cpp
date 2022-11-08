/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        if(n==1)
            return x;
        if(n==-1)
            return 1.0/x;
        // C++负数取余: -3%2 = -1
        if(n % 2==0){
            double half = myPow(x, n/2);
            return half * half;
        }
        else{
            // 这里不能直接乘x, 可能是-1, 同样要递归调用myPow(x, n%2)
            double half = myPow(x, n/2);
            return half * half * myPow(x, n%2);
        }
    }
};
// @lc code=end

