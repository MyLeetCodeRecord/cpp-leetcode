/*
 * @lc app=leetcode.cn id=762 lang=cpp
 *
 * [762] 二进制表示中质数个计算置位
 */

// @lc code=start
class Solution {
public:
    int lowbit(int x){
        return x & (-x);
    }
    bool isPrime(int x){
        if(x < 2)
            return false;
        for(int i=2; i<= x/i; i++){
            if(x % i == 0)
                return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        // 位数有限, 避免left~right区间比较大时重复判断prime
        vector<bool> prime_32(32, false);
        for(int i=1; i<32; i++)
            prime_32[i] = isPrime(i);
        int ans = 0;
        for(int i=left; i<=right; i++){
            int n = i;
            int cnt = 0;
            while(n != 0){
                n -= lowbit(n);     // 使用lowbit时n的变化
                cnt++;
            }
            ans += prime_32[cnt];
        }
        return ans;
    }
};
// @lc code=end

