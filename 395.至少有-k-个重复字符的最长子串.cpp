/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有 K 个重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size() < k)
            return 0;
        // 统计每个字符出现次数
        vector<int> hashTable(26, 0);  // 26个小写字母, 用vector吧
        for(char ch: s){
            hashTable[ch-'a']++;
        }
        // 以第一个出现的不满足k条件的字符作为分界, 并且抛弃掉它
        bool legal = true;
        int split = 0;
        for(split=0; split<s.size(); split++){
            if(hashTable[s[split]-'a'] < k){
                legal = false;
                break;
            }
        }
        // 终点: 如果当前s以完全满足k条件直接返回
        if(legal)
            return s.size();
        return max(longestSubstring(s.substr(0, split), k), longestSubstring(s.substr(split+1, s.size()-split-1), k));
    }
};
// @lc code=end

