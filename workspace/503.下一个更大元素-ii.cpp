/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> sk;
        vector<int> ans(n, -1);
        for(int i=0; i < 2 * n; i++){
            int cur = nums[i%n];
            while(!sk.empty() && nums[sk.top()] < cur){
                ans[sk.top()] = cur;
                sk.pop();
            }
            sk.push(i%n);
        }
        return ans;
    }
};
// @lc code=end

