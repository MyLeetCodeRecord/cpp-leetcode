/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
private:
    stack<int> sk;
    stack<int> minSk;
public:
    MinStack() {
        
    }
    void push(int x) {
        sk.push(x);
        if(minSk.empty() || x<=minSk.top()){
            minSk.push(x);
        }
    }
    void pop() {
        if(minSk.top() == sk.top())
            minSk.pop();
        sk.pop();
    }
    int top() {
        return sk.top();
    }
    int min() {
        return minSk.top();
    }
};
// @lc code=end

