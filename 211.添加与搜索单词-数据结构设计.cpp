/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
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
class WordDictionary {
private:
    TrieNode* trie;
public:
    WordDictionary() {
        trie = new TrieNode();
    }
    
    // 标准add
    void addWord(string word) {
        TrieNode* t = trie;
        for(char ch: word){
            if(t->child[ch-'a']==NULL)
                t->child[ch-'a'] = new TrieNode();
            t = t->child[ch-'a'];
        }
        t->isEnd = true;
    }
    
    // 带通配符的search
    bool dfs_search(string word, int cur,TrieNode* t){
        if(cur == word.size())
            return t->isEnd;
        // 是通配符"."
        if(word[cur]=='.'){
            for(int i=0; i<26; i++){
                if(t->child[i]!=NULL && dfs_search(word, cur+1, t->child[i]))
                    return true;
            }
        }
        // 不是通配符"."
        else{
            if(t->child[word[cur]-'a']!=NULL && dfs_search(word, cur+1, t->child[word[cur]-'a'])){
                return true;
            }
        }
        return false;
    }

    bool search(string word) {
        return dfs_search(word, 0, trie);
    }
};
// @lc code=end

