/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int> > ans;
    vector<int> path;
    void backtrack(vector<int> nums, int cur){
        if(path.size()>=2)
            ans.push_back(path);
        if(cur==nums.size())
            return ;
        unordered_set<int> st;
        for(int i=cur; i<nums.size(); i++){
            // 同一层去重, 与对排序情况进行去重的题目不一样
            if(st.find(nums[i])!=st.end())
                continue;
            if(path.empty() || nums[i] >= path.back()){
                st.insert(nums[i]);
                path.push_back(nums[i]);
                backtrack(nums, i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};
// @lc code=end

