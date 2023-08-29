/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

// @lc code=start
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size()!=popped.size())
            return false;
        stack<int> sk;
        int j = 0;  // popped中的指针
        for(int i=0; i<pushed.size(); i++){
            sk.push(pushed[i]);
            // 持续弹出
            while(!sk.empty() && sk.top() == popped[j]){
                sk.pop();
                j++;
            }
        }
        return j==popped.size();
    }
};
// @lc code=end

