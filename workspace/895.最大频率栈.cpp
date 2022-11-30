/*
 * @lc app=leetcode.cn id=895 lang=cpp
 *
 * [895] 最大频率栈
 */

// @lc code=start
class FreqStack {
public:
    // 对每个频率维护一个栈，同时维护元素的频率
    unordered_map<int, int> cnt_mp;         // val -> freq count
    unordered_map<int,stack<int>> sk_mp;    // 频率 -> 该频率的所有元素构成的栈
    int maxFreq = 0;

    FreqStack() {
    }
    
    void push(int val) {
        // 1. freq++
        cnt_mp[val]++;
        // 2. sk_mp[freq].push(val)
        sk_mp[cnt_mp[val]].push(val);
        // 3. 更新maxFreq, 如果必要
        maxFreq = max(maxFreq, cnt_mp[val]);
    }
    
    int pop() {
        // 1. 从maxFreq对应的stack中弹出栈顶元素
        int popped = sk_mp[maxFreq].top();
        sk_mp[maxFreq].pop();

        // 2. 如果没有maxFreq, 将maxFreq往小移动, 直到对应的stack.size()!=0
        if(sk_mp[maxFreq].size() == 0)
            maxFreq--;
        
        // 3. freq--
        cnt_mp[popped]--;
        
        return popped;
    }
};
// @lc code=end

