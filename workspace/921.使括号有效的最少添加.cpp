/*
 * @lc app=leetcode.cn id=921 lang=cpp
 *
 * [921] 使括号有效的最少添加
 */

// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        // leftCnt: 剩余左括号
        int leftCount = 0;
        for(auto &c : s){
            // 遇到左括号不做处理
            if(c == '(')
                leftCount++;
            // 遇到右括号, 左侧有左括号可以和它抵消, 则leftCnt--; 否则需要为它补一个左括号
            else{
                if(leftCount > 0)
                    leftCount--;
                else
                    ans++;
            }
        }
        // 如果有剩余左括号, 补充相同数量右括号
        ans += leftCount;
        return ans;
    }
};
// @lc code=end

