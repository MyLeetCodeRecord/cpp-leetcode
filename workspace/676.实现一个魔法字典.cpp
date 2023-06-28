/*
 * @lc app=leetcode.cn id=676 lang=cpp
 *
 * [676] 实现一个魔法字典
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
class MagicDictionary {
    TrieNode* trie;
public:
    MagicDictionary() {
    }
    void insert(string &word){
        TrieNode* t = trie;
        for(int i=0; i<word.size(); i++){
            if(t->child[word[i]-'a'] == NULL)
                t->child[word[i]-'a'] = new TrieNode();
            t = t->child[word[i]-'a'];
        }
        t->isEnd = true;
    }
    bool dfs(TrieNode* t, string &word, int cur, int modify){
        if(cur==word.size())
            return t->isEnd && modify==1;
        for(int i=0; i<26; i++){
            if(t->child[i]!=NULL){
                if(word[cur]-'a' == i){
                    if(dfs(t->child[i], word, cur+1, modify))
                        return true;
                }
                else if(modify == 0)
                    if(dfs(t->child[i], word, cur+1, modify+1))
                        return true;
            }
        }
        return false;
    }
    bool search(string word){
        return dfs(trie, word, 0, 0);
    }
    void buildDict(vector<string> dictionary) {
        trie = new TrieNode();
        for(string word: dictionary){
            insert(word);
        }
    }
};
// @lc code=end

