/*
 * @lc app=leetcode.cn id=1441 lang=cpp
 *
 * [1441] 用栈操作构建数组
 */

// @lc code=start
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int idx = 1;
        for(int num: target){
            if(num!=idx){
                ans.push_back("Push");
                ans.push_back("Pop");
                idx++;
            }
            else{
                ans.push_back("Push");
                idx++;
            }
        }
        return ans;
    }
};
// @lc code=end

