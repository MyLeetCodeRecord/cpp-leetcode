/*
 * @lc app=leetcode.cn id=1662 lang=cpp
 *
 * [1662] 检查两个字符串数组是否相等
 */

// @lc code=start
class Solution {
public:
    // 双指针
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0;
        int m = 0, n = 0;
        while(i<word1.size() && j<word2.size()){
            if(word1[i][m++] != word2[j][n++])
                return false;
            if(m==word1[i].size()){
                i++;
                m = 0;
            }
            if(n==word2[j].size()){
                j++;
                n = 0;
            }
        }
        return i==word1.size() && j==word2.size();
    }
};
// @lc code=end

