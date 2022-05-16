/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution {
public:
    // 分治法
    // 分治的条件应该是符号, 对于任意符号都可以分成左、右两个子问题
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        for(int i=0; i<expression.size(); i++){
            char cur = expression[i];
            if(cur == '+' || cur == '-' || cur == '*'){
                string left = expression.substr(0, i);
                string right = expression.substr(i+1, expression.size()-i);
                vector<int> leftResult = diffWaysToCompute(left);
                vector<int> rightResult = diffWaysToCompute(right);
                for(int i=0; i<leftResult.size(); i++){
                    for(int j=0; j<rightResult.size(); j++){
                        int l = leftResult[i];
                        int r = rightResult[i];
                        if(cur=='+'){
                            ans.push_back(l + r);
                        }
                        if(cur=='-'){
                            ans.push_back(l - r);
                        }
                        if(cur=='*'){
                            ans.push_back(l * r);
                        }
                    }
                }
            }
        }
        // 分治的最小问题: 数字
        // 没有出现标点才会使 ans 为空, 说明是数字
        if(ans.size()==0){
            return stoi(expression);
        }
        return ans;
    }
};
// @lc code=end

