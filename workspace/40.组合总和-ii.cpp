/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int> > ans;
    vector<int> path;
    int sum = 0;
    void backtrack(vector<int> candidates, int target, int cur){
        if(sum==target){
            ans.push_back(path);
            return ;
        }
        for(int i=cur; i<candidates.size(); i++){
            // 去重: 在树的同一层执行, 比如[1,1,7], 第二个1不再作为这一层的节点
            //       但不等同于不使用这个1了, 两个1的组合是在纵向体现的
            if(i>cur && candidates[i]==candidates[i-1])
                continue;
            sum += candidates[i];
            if(sum <= target){
                path.push_back(candidates[i]);
                backtrack(candidates, target, i+1);
                path.pop_back();
            }
            sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return ans;
    }
};
// @lc code=end

