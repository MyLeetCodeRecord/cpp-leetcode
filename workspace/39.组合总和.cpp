/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    // "允许重复选择", 也就是backtrack时继续使用当前i作为startIndex
    void backtrack(vector<int>&nums, int sum, int startIndex, int target){
        if(sum == target){
            ans.push_back(path);
            return ;
        }
        for(int i=startIndex; i<nums.size(); i++){
            path.push_back(nums[i]);
            sum += nums[i];
            if(sum <= target)
                backtrack(nums, sum, i, target);
            path.pop_back();
            sum -= nums[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, 0, 0, target);
        return ans;
    }
};
// @lc code=end

