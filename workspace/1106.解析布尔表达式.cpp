/*
 * @lc app=leetcode.cn id=1106 lang=cpp
 *
 * [1106] 解析布尔表达式
 */

// @lc code=start
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<int> sk;
        for(char ch: expression){
            if (ch != ',' && ch != ')')
                sk.push(ch); 
            else if(ch==')'){
                int cnt_t = 0;      // 计数true/false的个数
                int cnt_f = 0;
                while(sk.top() != '('){ // 直到遇到一层"(", 进行一次运算
                    if(sk.top() == 't')
                        cnt_t++;
                    else
                        cnt_f++;
                    sk.pop();
                }
                sk.pop();           // 删除左括号
                char op = sk.top(); // 如何处理上面这几个数
                sk.pop();
                // 根据运算符进行运算
                if(op=='&'){
                    if(cnt_f != 0)
                        sk.push('f');
                    else
                        sk.push('t');
                }
                else if(op=='|'){
                    if(cnt_t != 0)
                        sk.push('t');
                    else
                        sk.push('f');
                }
                else if(op=='!'){
                    if(cnt_t > 0)
                        sk.push('f');
                    else
                        sk.push('t');
                }
            }
        }
        return sk.top() == 't';
    }
};
// @lc code=end

