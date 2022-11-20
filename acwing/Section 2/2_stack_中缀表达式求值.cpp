#include <cstdio>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

unordered_map<char, int> priority{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
stack<int> numSk;
stack<char> symbolSk;

// 最好不要用eval()命名, 在leetcode里和stl冲突
void calc_eval(){
    auto b = numSk.top();   numSk.pop();
    auto a = numSk.top();   numSk.pop();
    auto symbol = symbolSk.top(); symbolSk.pop();
    int ans = 0;
    if(symbol == '+')
        ans = a + b;
    if(symbol == '-')
        ans = a - b;
    if(symbol == '*')
        ans = a * b;
    if(symbol == '/')
        ans = a / b;
    numSk.push(ans);
}
int main(){
    string str;
    cin>>str;
    for(int i=0; i<(int)str.size(); i++){
        auto c = str[i];
        // 数字
        if(isdigit(c)){
            int num = 0;
            int j = i;
            while(j<(int)str.size() && isdigit(str[j])){
                num = num * 10 + (str[j]-'0');
                j++;
            }
            i = j-1;
            numSk.push(num);
        }
        // 下面这两个条件是对括号的判断, 没有括号的中缀表达式求值题目也不会有影响

        // 如果是左括号, 这种情况不能和+-*/的情况合并, 或者将"("的优先级设为最高
        else if(c == '('){
            symbolSk.push('(');
        }
        // 如果是右括号, 则计算直到找到匹配的左括号
        else if(c == ')'){
            while(symbolSk.top()!='(')
                calc_eval();
            symbolSk.pop();
        }
        // 符号: 加入当前符号前, 要保证前面更大优先级的运算已经结束
        // 如果是更低优先级的符号, 需要将更高优先级的符号先计算完
        else{
            while(!symbolSk.empty() && priority[symbolSk.top()] >= priority[c])
                calc_eval();
            symbolSk.push(c);
        }
    }
    // 剩余计算
    while(!symbolSk.empty())
        calc_eval();
    cout<<numSk.top()<<endl;
    return 0;
}