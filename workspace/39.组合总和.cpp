/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int> > ans;
    vector<int> path;
    int sum = 0;
    void backtrack(vector<int>& candidates, int target, int cur){
        if(sum==target){
            ans.push_back(path);
        }
        for(int i=cur; i<candidates.size(); i++){
            sum += candidates[i];
            if(sum <= target){
                path.push_back(candidates[i]);
                backtrack(candidates, target, i);
                path.pop_back();
            }
            sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0);
        return ans;
    }
};
// @lc code=end

