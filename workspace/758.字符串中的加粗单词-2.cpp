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
    TrieNode* trie;
public:
    void insert(string &word){
        TrieNode* t = trie;
        for(int i=0; i<word.size(); i++){
            if(t->child[word[i]-'a']==NULL)
                t->child[word[i]-'a'] = new TrieNode();
            t = t->child[word[i]-'a'];
        }
        t->isEnd = true;
    }
    // 遇到isEnd则进行一个字符串中[cur, i]的单词的标记
    void search(string &word, int cur, vector<bool>& bold){
        TrieNode* t = trie;
        for(int i=cur; i<word.size(); i++){
            if(t->child[word[i]-'a']==NULL)
                return ;
            t = t->child[word[i]-'a'];
            if(t->isEnd == true){
                for(int j=cur; j<=i; j++){
                    bold[j] = true;
                }
            }
        }
    }
    string boldWords(vector<string>& words, string s) {
        trie = new TrieNode();
        for(string word : words){
            insert(word);
        }
        vector<bool> bold(s.size(), false);
        for(int start=0; start<s.size(); start++){
            search(s, start, bold);
        }
        string ans = "";
        // 只枚举起点
        for(int i=0; i<s.size(); i++){
            if(bold[i] == true){
                ans += "<b>";
                int j = i;
                while(j<s.size() && bold[j]==true){
                    j++;
                }
                ans += s.substr(i, j-i);
                ans += "</b>";
                i = j - 1;
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};