/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> sk;    // 中间结果可能是long long
        for(string token : tokens){
            if(token=="+" || token=="-" || token=="*" || token=="/"){
                long long b = sk.top();
                sk.pop();
                long long a = sk.top();
                sk.pop();
                if(token=="+")
                    sk.push(a+b);
                if(token=="-")
                    sk.push(a-b);
                if(token=="*")
                    sk.push(a*b);
                if(token=="/")
                    sk.push(a/b);
            }
            else{
                sk.push(stoi(token));
            }
        }
        return sk.top();
    }
};
// @lc code=end

