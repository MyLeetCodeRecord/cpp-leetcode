/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int> > ans;
    vector<int> path;

    // 有重复元素, 要去重
    void backtrack(vector<int> nums, int cur){
        ans.push_back(path);
        if(cur==nums.size())
            return ;
        for(int i=cur; i<nums.size(); i++){
            // 同LC40, 在同一层去重, 相同元素则不再在这一层建立节点
            if(i>cur && nums[i]==nums[i-1])
                continue;
            path.push_back(nums[i]);
            backtrack(nums, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return ans;
    }
};
// @lc code=end

