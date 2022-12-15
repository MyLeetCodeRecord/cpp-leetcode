/*
 * @lc app=leetcode.cn id=820 lang=cpp
 *
 * [820] 单词的压缩编码
 */

// @lc code=start
struct Trie{
    Trie* child[26];
    Trie(){
        for(int i=0; i<26; i++)
            child[i] = NULL;
    }
};
class Solution {
private:
    Trie* trie;
    int cnt = 0;
public:
    bool static cmp(string l, string r){
        return l.size() > r.size();
    }
    void insert(string word){
        Trie* t = trie;
        bool diff = false;
        for(char ch: word){
            if(t->child[ch-'a']==NULL){
                t->child[ch-'a'] = new Trie();
                diff = true;
            }
            t = t->child[ch-'a'];
        }
        // 如果是新建立的叶节点, 则计数
        if(diff)
            cnt += word.size()+1;
    }
    int minimumLengthEncoding(vector<string>& words) {
        trie = new Trie();
        sort(words.begin(), words.end(), cmp);
        for(string& word: words){
            reverse(word.begin(), word.end());
            insert(word);
        }
        return cnt;
    }
};
// @lc code=end

