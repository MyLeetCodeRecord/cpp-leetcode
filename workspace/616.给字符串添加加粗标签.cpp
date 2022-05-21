struct TrieNode{
    TrieNode* child[80];
    bool isEnd;
    TrieNode(){
        for(int i=0; i<80; i++){
            child[i] = NULL;
        }
        isEnd = false;
    }
};
class Solution {
public:
    void add(TrieNode* trie, string word) {
        TrieNode* t = trie;
        for(char ch: word){
            if(t->child[ch-'/']==NULL){
                t->child[ch-'/'] = new TrieNode();
            }
            t = t->child[ch-'/'];
        }
        t->isEnd = true;
    }
    bool search(TrieNode* trie, string word) {
        TrieNode* t = trie;
        for(char ch: word){
            if(t->child[ch-'/'] == NULL){
                return false;
            }
            t = t->child[ch-'/'];
        }
        return t->isEnd;
    }
    bool startsWith(TrieNode* trie, string prefix) {
        TrieNode* t = trie;
        for(char ch: prefix){
            if(t->child[ch-'/'] == NULL){
                return false;
            }
            t = t->child[ch-'/'];
        }
        return true;
    }
    string addBoldTag(string s, vector<string>& words) {
        // '{'在ascii码中是小写z的下一个, 方便不单独处理边界
        s = '/' + s + '/';
        // 标记哪些加粗
        vector<bool> bold(s.size(), false);
        // words构建到Trie中
        TrieNode* trie = new TrieNode();
        vector<int> lenList;
        for(string w : words){
            add(trie, w);
            lenList.push_back(w.size());
        }
        sort(lenList.begin(), lenList.end());
        // 对于字符串的每个开始位置 i , 在字符串中搜索, 如果这个s.sub(i,len)在树中, 就标记, 不在就直接下一个起始位置[这个需要Prefix支持]
        for(int i=0; i<s.size(); i++){
            for(int len : lenList){
                cout<<s.substr(i, len)<<endl;
                if(search(trie, s.substr(i, len))==true){
                    for(int k=0; k<len; k++)
                        bold[i+k] = true;
                }
                else if(startsWith(trie, s.substr(i, len))==false){
                    break;
                }
            }
        }
        string ans = "";
        for(int i=0; i<s.size(); i++){
            // prehandler
            if(bold[i]==true && bold[i-1]==false)
                ans += "<b>";
            ans += s[i];
            // posthandler
            if(bold[i]==true && bold[i+1]==false)
                ans += "</b>";
        }
        return ans.substr(1, ans.size()-2);
    }
};