/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        // 1. 构建单词的二进制数字表示
        vector<int> binaryWord(n);
        for(int i=0; i<n; i++){
            for(char ch: words[i]){
                binaryWord[i] |= (1<<(ch-'a'));
            }
        }
        // 2. 没有公共字母的单词, 二进制(哈希)表示相&应该为0
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if((binaryWord[i]&binaryWord[j])==0){
                    int tmp = words[i].size() * words[j].size();
                    ans = max(ans, tmp);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

