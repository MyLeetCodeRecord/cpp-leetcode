/*
 * @lc app=leetcode.cn id=890 lang=cpp
 *
 * [890] 查找和替换模式
 */

// @lc code=start
class Solution {
public:
    // 对位比较, 建立word->pattern的映射  &&  set保证没有两个字母映射到同一个字母
    bool isSamePattern(string& word, string& pattern){
        map<char, char> mp;
        unordered_set<char> st;
        for(int i=0; i<word.size(); i++){
            if(mp.find(word[i])==mp.end()){
                if(st.find(pattern[i])!=st.end())
                    return false;
                mp[word[i]] = pattern[i];
                st.insert(pattern[i]);
            }
            else if(mp[word[i]] != pattern[i]){
                return false;
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(string word: words){
            if(isSamePattern(word, pattern)==true){
                ans.push_back(word);
            }
        }
        return ans;
    }
};
// @lc code=end

