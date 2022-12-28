/*
 * @lc app=leetcode.cn id=1750 lang=cpp
 *
 * [1750] 删除字符串两端相同字符后的最短长度
 */

// @lc code=start
class Solution {
public:
    // 双指针
    int minimumLength(string s) {
        int n = s.size();
        int i = 0, j = n-1;
        while(i < j){
            if(s[i] == s[j]){
                while(i<j && s[i+1]==s[i]){
                    i++;
                }
                while(i<j && s[j-1]==s[j]){
                    j--;
                }
                i++;
                j--;
            }
            else        // 这句可以通过while(i<j && s[i]==s[j])替代
                break;
        }
        return max(j-i+1, 0);
    }
};
// @lc code=end

