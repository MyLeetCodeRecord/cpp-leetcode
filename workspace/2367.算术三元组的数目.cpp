/*
 * @lc app=leetcode.cn id=2367 lang=cpp
 *
 * [2367] 算术三元组的数目
 */

// @lc code=start
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        bitset<310> bs; // 200+2*50=300
        for(int x : nums)
            bs[x] = 1;
        int ans = 0;
        for(int x: nums){
            ans += bs[x+diff] & bs[x+2*diff];
        }
        return ans;
    }
};
// @lc code=end

