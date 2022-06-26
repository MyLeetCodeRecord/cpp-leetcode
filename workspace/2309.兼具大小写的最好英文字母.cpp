/*
 * @lc app=leetcode.cn id=2309 lang=cpp
 *
 * [2309] 兼具大小写的最好英文字母
 */

// @lc code=start
class Solution {
public:
    string greatestLetter(string s) {
        vector<bool> aTable(26, false);
        vector<bool> ATable(26, false);
        
        for(char ch : s){
            if(ch >= 'a' && ch <= 'z'){
                aTable[ch-'a'] = true;
            }
            if(ch >='A' && ch <= 'Z'){
                ATable[ch-'A'] = true;
            }
        }
        string ans = "";
        for(int i=26; i>=0; i--){
            if(aTable[i]==true && ATable[i]==true){
                ans += ('A'+i);
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

