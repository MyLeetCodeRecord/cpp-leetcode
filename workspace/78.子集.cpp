/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int> > ans;
    vector<int> path;

    // 无重复元素, 不用考虑去重
    void backtrack(vector<int> nums, int cur){
        ans.push_back(path);
        if(cur==nums.size())
            return ;
        for(int i=cur; i<nums.size(); i++){
            path.push_back(nums[i]);
            backtrack(nums, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};
// @lc code=end

