/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
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
        // 全排列中for循环从0开始, 但是要保证不重复使用, 并且要去重
        for(int i=0; i<nums.size(); i++){
            // 同一层去重: 如果前一个not used, 不需要去重
            if(i>0 && !used[i-1] && nums[i]==nums[i-1])
                continue;
            if(!used[i]){
                path.push_back(nums[i]);
                used[i] = true;
                backtrack(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtrack(nums, used);
        return ans;
    }
};
// @lc code=end

