/*
 * @lc app=leetcode.cn id=648 lang=cpp
 *
 * [648] 单词替换
 */

// @lc code=start
struct TrieNode{
    TrieNode* child[26];
    string word;    // 直接在叶子节点存储单词, 就不需要再重新遍历一遍拼接单词了
    TrieNode(){
        for(int i=0; i<26; i++)
            child[i] = NULL;
        word = "";
    }
};
class Solution {
public:
    TrieNode* trie;
    void insert(string word){
        TrieNode* t = trie;
        for(int i=0; i<word.size(); i++){
            if(t->child[word[i]-'a']==NULL)
                t->child[word[i]-'a'] = new TrieNode();
            t = t->child[word[i]-'a'];
        }
        t->word = word;
    }
    string search(string word, TrieNode* trie){
        TrieNode* t = trie;
        for(char ch: word){
            // 如果在miss之前没有找到词根, 则说明没有词根, 直接返回
            if(t->child[ch-'a']==NULL){
                return word;
            }
            // 遇到最短词根(一定是搜索路径上最先遇到不为空的word)
            if(t->child[ch-'a']->word.size() > 0){
                return t->child[ch-'a']->word;
            }
            t = t->child[ch-'a'];
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        trie = new TrieNode();
        for(string word: dictionary){
            insert(word);
        }
        int n = sentence.size();
        string ans = "";
        for(int i=0; i<n; i++){
            // 截取一个单词
            if(sentence[i]!=' '){
                int j = i;
                while(j<n && sentence[j]!=' ')
                    j++;
                string sub = sentence.substr(i, j-i);
                ans += search(sub);
                ans += " ";
                i = j;
            }
        }
        return ans.substr(0, ans.size()-1); 
    }
};
// @lc code=end

