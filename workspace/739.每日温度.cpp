/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        for(int i=0; i<temperatures.size(); i++){
            int cur = temperatures[i];
            while(!sk.empty() && temperatures[sk.top()]<cur){
                ans[sk.top()] = i-sk.top();
                sk.pop();
            }
            sk.push(i);
        }
        return ans;
    }
};
// @lc code=end

