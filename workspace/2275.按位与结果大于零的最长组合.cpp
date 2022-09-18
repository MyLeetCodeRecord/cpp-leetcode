/*
 * @lc app=leetcode.cn id=2275 lang=cpp
 *
 * [2275] 按位与结果大于零的最长组合
 */

// @lc code=start
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> cnt(32, 0);
        for(int x : candidates){
            int k = 0;
            while(x != 0){
                cnt[k++] += (x & 1);
                x = x>>1;
            }
        }
        int ans = 0;
        for(int i=0; i<32; i++){
            ans = max(ans, cnt[i]);
        }
        return ans;
    }
};
// @lc code=end

