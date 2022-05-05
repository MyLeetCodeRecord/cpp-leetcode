/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */

// @lc code=start
struct TrieNode{
    TrieNode* child[26];
    bool isEnd;
    TrieNode(){
        for(int i=0; i<26; i++)
            child[i] = NULL;
        isEnd = false;
    }
};
class Solution {
private:
    TrieNode* trie;
public:
    void add(string word){
        TrieNode* t = trie;
        for(char ch: word){
            if(t->child[ch-'a'] == NULL){
                t->child[ch-'a'] = new TrieNode();
            }
            t = t->child[ch-'a'];
        }
        isEnd = true;
    }
    string longestWord(vector<string>& words) {
        // 将words存储到一棵Trie中
        for(int i=0; i<words; i++){
            add(words[i]);
        }
        
    }
};
// @lc code=end

