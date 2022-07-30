/*
 * @lc app=leetcode.cn id=676 lang=cpp
 *
 * [676] 实现一个魔法字典
 */

// @lc code=start
struct Trie{
    Trie* child[26];
    bool isEnd;
    Trie(){
        for(int i=0; i<26; i++)
            child[i] = NULL;
        isEnd = false;
    }
};
class MagicDictionary {
private:
    Trie* trie;
public:
    MagicDictionary() {
        
    }
    void add(string word){
        Trie* t = trie;
        for(char ch: word){
            if(t->child[ch-'a']==NULL){
                t->child[ch-'a'] = new Trie();
            }
            t = t->child[ch-'a'];
        }
        t->isEnd = true;
    }
    // 类似“带通配符的search” - DFS
    bool dfs_search(string word, int changed, int cur, Trie* t){
        if(changed > 1 || t == NULL)
            return false;
        if(cur == word.size()){
            return t->isEnd && changed==1;
        }
        for(int i=0; i<26; i++){
            if(t->child[i] != NULL){
                // 不修改
                if(i==word[cur]-'a'){
                    if(dfs_search(word, changed, cur+1, t->child[i]))
                        return true;
                }
                // 修改
                else if(changed==0 && t->child[i] != NULL && dfs_search(word, changed+1, cur+1, t->child[i]))
                    return true;
            }
        }
        return false;
    }
    bool search(string searchWord) {
        return dfs_search(searchWord, 0, 0, trie);
    }
    void buildDict(vector<string> dictionary) {
        trie = new Trie();
        for(string word: dictionary){
            add(word);
        }
    }
};
// @lc code=end

