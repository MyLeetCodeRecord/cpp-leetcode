/*
 * @lc app=leetcode.cn id=1175 lang=cpp
 *
 * [1175] 质数排列
 */

// @lc code=start
class Solution {
public:
    bool isZhiShu(int n){
        if(n==1)
            return false;
        for(int i=2; i<=sqrt(n); i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
    int A(int n){
        long long ans = 1;
        for(int i=1; i<=n; i++){
            ans = (ans*i) % 1000000007;
        }
        return ans % 1000000007;
    }
    int numPrimeArrangements(int n) {
        int cnt = 0;
        for(int i=1; i<=n; i++){
            if(isZhiShu(i)){
                cnt++;
            }
        }
        int a = A(cnt);
        int b = A(n-cnt);
        return (1LL * a * b) % 1000000007;
    }
};
// @lc code=end

