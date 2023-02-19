/*
 * @lc app=leetcode.cn id=1237 lang=cpp
 *
 * [1237] 找出给定方程的正整数解
 */

// @lc code=start
class Solution {
public:
    // 递增 & 两数之和 => 相向双指针
    // 注意边界不再是 l<r, 而是 l<=1000 && r>=1
    vector<vector<int>> findSolution(CustomFunction& cf, int z) {
        int l = 1, r = 1000;
        vector<vector<int>> ans;
        while(l<=1000 && r>=1){
            int val = cf.f(l, r);
            if(val == z)
                ans.push_back({l++, r--});
            else if(val < z)
                l++;
            else
                r--;
        }
        return ans;
    }
};
// @lc code=end

