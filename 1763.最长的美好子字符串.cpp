/*
 * @lc app=leetcode.cn id=1763 lang=cpp
 *
 * [1763] 最长的美好子字符串
 */

// @lc code=start
class Solution {
public:
    string longestNiceSubstring(string s) {
        vector<vector<bool> > hashTable(26, vector<bool>(2, false));
        for(char ch: s){
            if(ch > 'Z')    // 小写字母
                hashTable[ch-'a'][1] = true;
            else
                hashTable[ch-'A'][0] = true;
        }
        bool happy = true;
        int split = 0;
        for(int i=0; i<s.size(); i++){
            char index = (s[i] > 'Z') ? 'a' : 'A';   // 判断大小写
            if(hashTable[s[i]-index][0] == false || hashTable[s[i]-index][1] == false){
                happy = false;
                split = i;
            }
        }
        if(happy)
            return s;
        string left = longestNiceSubstring(s.substr(0, split));
        string right = longestNiceSubstring(s.substr(split+1, s.size()-split-1));
        if(left.size()>right.size())
            return left;
        else if(left.size()<right.size())
            return right;
        else
            return left;
    }
};
// @lc code=end

