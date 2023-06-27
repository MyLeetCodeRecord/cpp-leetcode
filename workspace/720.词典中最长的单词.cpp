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
void insert(TrieNode* trie, string word){
    TrieNode* t = trie;
    for(int i=0; i<(int)word.size(); i++){
        if(t->child[word[i]-'a']==NULL)
            t->child[word[i]-'a'] = new TrieNode();
        t = t->child[word[i]-'a'];
    }
    t->isEnd = true;
}
int search(TrieNode* trie, string word){
    TrieNode* t = trie;
    for(int i=0; i<(int)word.size(); i++){
        if(t->child[word[i]-'a']==NULL || t->child[word[i]-'a']->isEnd==false)
            return false;
        t = t->child[word[i]-'a'];
    }
    return t->isEnd;
}
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [&](const string &l, const string &r){
            if(l.size()==r.size())
                return l < r;
            return l.size() < r.size();
        });
        TrieNode* trie = new TrieNode();
        string ans = "";
        for(int i=0; i<words.size(); i++){
            insert(trie, words[i]);
            if(search(trie, words[i]) && words[i].size()>ans.size())
                ans = words[i];
        }
        return ans;
    }
};
// @lc code=end

