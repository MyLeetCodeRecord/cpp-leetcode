/*
 * @lc app=leetcode.cn id=1255 lang=cpp
 *
 * [1255] 得分最高的单词集合
 */

// @lc code=start
class Solution {
public:
    // 回溯
    int ans = 0;
    int sum = 0;
    void backtrack(vector<string>& words, int cur, vector<int> &score, vector<int> &mp){
        if(cur==words.size()){
            return ;
        }
        // 枚举下一个要选的单词
        for(int i=cur; i<words.size(); i++){
            // 检查是否能插入(剩余字符数量足够), 顺便计算单词价值
            string word = words[i];
            bool flag = true;
            int val = 0;
            for(char ch: word){
                mp[ch-'a']--;
                val += score[ch-'a'];
                if(mp[ch-'a']<0)
                    flag = false;
            }
            if(flag){
                sum += val;
                ans = max(ans, sum);
                backtrack(words, i+1, score, mp);
                sum -= val;
            }
            for(char ch: word){
                mp[ch-'a']++;
            }
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> mp(26, 0);
        for(char ch : letters){
            mp[ch-'a']++;
        }
        backtrack(words, 0, score, mp);
        return ans;
    }
};
// @lc code=end

