/*
 * @lc app=leetcode.cn id=2311 lang=cpp
 *
 * [2311] 小于等于 K 的最长二进制子序列
 */

// @lc code=start
class Solution {
public:
    int trans(int n){
        int tmp = n;
        int k = 0;
        while(n / 2!=0){
            n /= 2;
            k++;
        }
        int highest = 1;
        while(k!=0){
            highest *= 2;
            k--;
        }
        return tmp-highest;
    }
    int longestSubsequence(string s, int k) {
        int ans = 1;
        int left = 0;
        int right = 0;
        int val = 0;
        while(right < s.size()){
            val = val * 2 + (s[right++]-'0');
            while(val > k && left<right){
                left++;
                val = trans(val);
            }
            ans = max(ans, right-left);
        }
        return ans;
    }
};
// @lc code=end

