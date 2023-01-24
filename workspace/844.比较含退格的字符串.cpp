/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution {
public:
    string trans(string s){
        int fast = 0;
        int slow = 0;
        while(fast < s.size()){
            if(s[fast] == '#'){
                if(slow != 0)
                    slow--;
                fast++;
            }
            else{
                s[slow++] = s[fast++];
            }
        }
        return s.substr(0, slow);
    }
    bool backspaceCompare(string s, string t) {
        return trans(s) == trans(t);
    }
};
// @lc code=end

