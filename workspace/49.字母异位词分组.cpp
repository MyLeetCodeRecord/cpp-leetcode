/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    // O(n·k·log(k))
    // => 将排序后的字符作为key, 原字符串作为value

    // O(n·k)时间复杂度
    // => 用counter作为key, 原字符串作为value
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> mp;
        for(string str: strs){
            string dict = string(26, '0');
            map<char, int> cntMp;
            for(char ch: str){
                cntMp[ch]++;
            }
            mp[cntMp].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto &[k,v]: mp){
            ans.push_back(v);
        }
        return ans;
    }
};
// @lc code=end

