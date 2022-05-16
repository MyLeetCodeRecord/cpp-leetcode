/*
 * @lc app=leetcode.cn id=648 lang=cpp
 *
 * [648] 单词替换
 */

// @lc code=start
struct TrieNode{
    TrieNode* child[26];
    string word;
    TrieNode(){
        for(int i=0; i<26; i++)
            child[i] = NULL;
        word = "";
    }
};
class Solution {
public:
    void add(string word, TrieNode* trie){
        TrieNode* t = trie;
        for(char ch: word){
            if(t->child[ch-'a']==NULL)
                t->child[ch-'a'] = new TrieNode();
            t = t->child[ch-'a'];
        }
        t->word = word;
    }
    string search(string word, TrieNode* trie){
        TrieNode* t = trie;
        for(char ch: word){
            // 不存在词根直接返回
            if(t->child[ch-'a']==NULL){
                return word;
            }
            // 遇到最短词根(一定是搜索路径上最先遇到不为空的word)
            if(t->child[ch-'a']!=NULL && t->child[ch-'a']->word.size() > 0){
                return t->child[ch-'a']->word;
            }
            t = t->child[ch-'a'];
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* trie = new TrieNode();
        for(string word : dictionary){
            add(word, trie);
        }
        string ans = "";
        int left = 0;
        int right = 0;
        sentence += " ";
        for(int i=0; i<sentence.size(); i++){
            for(int j=i+1; j<sentence.size(); j++){
                if(sentence[j] == ' '){
                    string sub = sentence.substr(i, j-i);
                    ans += search(sub, trie);
                    ans += " ";
                    i = j+1;
                }
            }
        }
        return ans.substr(0, ans.size()-1);
    }
};
// @lc code=end

