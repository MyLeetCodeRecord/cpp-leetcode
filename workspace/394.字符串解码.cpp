/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<int> numSk;
        stack<string> strSk;
        int num = 0;
        string str = "";
        for(int i=0; i<n; i++){
            // 数字
            if(s[i]>='0' && s[i]<='9'){
                num = num*10 + (s[i]-'0');
            }
            // 字符串
            else if(s[i]>='a' && s[i]<='z'){
                str += s[i];
            }
            // '['
            else if(s[i]=='['){
                numSk.push(num);
                strSk.push(str);
                num = 0;
                str = "";
            }
            // ']'
            else{
                int x = numSk.top();
                numSk.pop();
                for(int a=0; a<x; a++){
                    strSk.top() += str;
                }
                str = strSk.top();
                strSk.pop();    // 当前'['已经被解除了, 变成被重复字符串了, 所以这里要pop
            }
        }
        return str;
    }
};
// @lc code=end

