/*
 * @lc app=leetcode.cn id=982 lang=cpp
 *
 * [982] 按位与为零的三元组
 */

// @lc code=start
class Solution {
public:
    int countTriplets(vector<int>& nums) {
        // 预处理所有二元组
        int cnt[1<<16];
        memset(cnt, 0, sizeof cnt);
        int n = nums.size();
        for(int x: nums){
            for(int y: nums){
                cnt[x & y]++;
            }
        }
        int ans = 0;
        // 子集优化: 枚举(x^0xffff)的子集, 子集中的值与x相与一定为0
        for(int x : nums){
            x = x ^ 0xffff;
            int sub = x;
            while(sub != 0){
                ans += cnt[sub];
                sub = (sub-1) & x;
            }
            ans += cnt[0];
        }
        return ans;
    }
};
// @lc code=end

