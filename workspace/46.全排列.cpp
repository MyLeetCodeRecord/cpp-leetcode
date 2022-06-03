/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int> > ans;
    vector<int> path;
    void backtrack(vector<int> nums, vector<bool> used){
        if(path.size()==nums.size()){
            ans.push_back(path);
            return ;
        }
        // 全排列中for循环从0开始, 但是要保证不重复使用
        for(int i=0; i<nums.size(); i++){
            if(!used[i]){
                path.push_back(nums[i]);
                used[i] = true;
                backtrack(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtrack(nums, used);
        return ans;
    }
};
// @lc code=end

