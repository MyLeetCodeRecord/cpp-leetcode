/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution {
private:
    stack<int> numSk;
    stack<char> symbolSk;
    unordered_map<char, int> priority{{'+',1},{'-',1},{'*',2},{'/',2}};
public:
    void calc_eval(){
        int b = numSk.top();  numSk.pop();
        int a = numSk.top();  numSk.pop();
        char op = symbolSk.top();  symbolSk.pop();
        int num = 0;
        if(op=='+')
            num = a+b;
        else if(op=='-')
            num = a-b;
        else if(op=='*')
            num = a*b;
        else
            num = a/b;
        numSk.push(num);
    }
    int calculate(string s) {
        for(int i=0; i<(int)s.size(); i++){
            auto c = s[i];
            if(c==' ')
                continue;
            if(isdigit(c)){
                int num = 0;
                int j = i;
                while(j<(int)s.size() && isdigit(s[j])){
                    num = num * 10 + (s[j]-'0');
                    j++;
                }
                i = j-1;
                numSk.push(num);
            }
            else{
                while(!symbolSk.empty() && priority[symbolSk.top()] >= priority[c])
                    calc_eval();
                symbolSk.push(c);
            }
        }
        while(!symbolSk.empty())
            calc_eval();
        return numSk.top();
    }
};
// @lc code=end

