/*
 * @lc app=leetcode.cn id=820 lang=cpp
 *
 * [820] 单词的压缩编码
 */

// @lc code=start
struct TrieNode{
    TrieNode* child[26];
    TrieNode(){
        for(int i=0; i<26; i++)
            child[i] = NULL;
    }
};
class Solution {
public:
    TrieNode* trie = new TrieNode();
    void insert(string &word){
        TrieNode* t = trie;
        for(int i=0; i<word.size(); i++){
            if(t->child[word[i]-'a'] == NULL)
                t->child[word[i]-'a'] = new TrieNode();
            t = t->child[word[i]-'a']; 
        }
    }
    bool search(string &word){
        TrieNode* t = new TrieNode();
        for(int i=0; i<word.size(); i++){
            if(t->child[word[i]-'a'] == NULL)
                return false;
            t = t->child[word[i]-'a'];
        }
        return true;
    }
    int minimumLengthEncoding(vector<string>& words) {
        // 先放长的, 再放短的
        sort(words.begin(), words.end(), [&](const string &l, const string &r){
            return l.size() > r.size();
        });
        int ans = 0;
        for(string word: words){
            // 单词逆序
            reverse(word.begin(), word.end());
            if(search(word)==false){
                insert(word);
                ans += word.size();
            }
        }
        return ans;
    }
};
// @lc code=end

