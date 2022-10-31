/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 */

// @lc code=start
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> sk;
        for(int i=0; i<n; i++){
            while(!sk.empty() && cur<=sk.top()){
                sk.pop();
            }
        }
    }
};
// @lc code=end

