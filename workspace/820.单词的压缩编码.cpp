/*
 * @lc app=leetcode.cn id=820 lang=cpp
 *
 * [820] 单词的压缩编码
 */

// @lc code=start
struct Trie{
    Trie* child[26];
    bool isEnd;
    Trie(){
        for(int i=0; i<26; i++)
            child[i] = NULL;
        isEnd = true;
    }
};
class Solution {
public:
    void insert(Trie* trie, string word){
        Trie* t = trie;
        for(char ch: word){
            if(t->child[ch-'a']==NULL)
                t->child[ch-'a'] = new Trie();
            t = t->child[ch-'a'];
        }
        t->isEnd = true;
    }
    bool search(Trie* trie, string word){
        Trie* t = trie;
        for(char ch: word){
            if(t->child[ch-'a']==NULL)
                return false;
            t = t->child[ch-'a'];
        }
        return true;
    }
    int minimumLengthEncoding(vector<string>& words) {
        Trie* trie = new Trie();
        sort(words.begin(), words.end(), [&](string& l, string &r){
            return l.size() > r.size();
        });
        int ans = 0;
        for(string &word: words){
            reverse(word.begin(), word.end());
            if(!search(trie, word)){
                insert(trie, word);
                ans += (word.size()+1);
            }
        }
        return ans;
    }
};
// @lc code=end

