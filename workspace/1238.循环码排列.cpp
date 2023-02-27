/*
 * @lc app=leetcode.cn id=1238 lang=cpp
 *
 * [1238] 循环码排列
 */

// @lc code=start
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int N = (1<<n);
        vector<int> ans(N, 0);
        for(int i=0; i<N; i++){
            int G_i = i^(i/2);
            ans[(i-start+1+N) % N] = G_i;
        }
        return ans;
    }
};
// @lc code=end

