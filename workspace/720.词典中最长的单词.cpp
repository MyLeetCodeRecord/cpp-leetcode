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
        t->isEnd = true;
    }
    bool search(string word){
        TrieNode* t = trie;
        for(char ch: word){
            // word是存储在边上的
            if(t->child[ch-'a']==NULL || t->child[ch-'a']->isEnd==false){
                return false;
            }
            t = t->child[ch-'a'];
        }
        return t->isEnd;
    }
    string longestWord(vector<string>& words) {
        // 先排序, 满足题目字典序要求, 并且insert和search可以在一个循环内完成
        // 先插入短的, 保证插入长的单词时, 它的前缀已经被加入了(如果有)
        sort(words.begin(), words.end());
        trie = new TrieNode();
        string ans = "";
        for(int i=0; i<words.size(); i++){
            // 将words存储到一棵Trie中
            add(words[i]);
            if(search(words[i])==true && words[i].size()>ans.size()){
                ans = words[i];
            }
        }
        return ans;
    }
};
// @lc code=end

