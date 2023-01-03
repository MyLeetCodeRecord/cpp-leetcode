/*
 * @lc app=leetcode.cn id=2042 lang=cpp
 *
 * [2042] 检查句子中的数字是否递增
 */

// @lc code=start
class Solution {
public:
    bool areNumbersAscending(string s) {
        int n = s.size();
        int pre = -1;
        for(int i=0; i<n; i++){
            if(isdigit(s[i])){
                int x = 0;
                int j = i;
                while(j<n && isdigit(s[j])){
                    x *= 10;
                    x += (s[j]-'0');
                    j++;
                }
                i = j-1;
                if(x <= pre)
                    return false;
                pre = x;
            }
        }
        return true;
    }
};
// @lc code=end

