/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
struct TrieNode{
    TrieNode* child[26];
    string word;
    TrieNode(){
        for(int i=0; i<26; i++)
            child[i] = NULL;
        word = "";
    }
};
class Solution {
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    void insert(TrieNode* trie, string &word){
        TrieNode* t = trie;
        for(int i=0; i<word.size(); i++){
            if(t->child[word[i]-'a'] == NULL)
                t->child[word[i]-'a'] = new TrieNode();
            t = t->child[word[i]-'a'];
        }
        t->word = word;
    }
    void DFS(vector<vector<char>>& board, int x, int y, TrieNode* trie, unordered_set<string> &st){
        char ch = board[x][y];
        if(trie->child[ch-'a'] == NULL)
            return ;
        if(trie->child[ch-'a']->word != "")
            st.insert(trie->child[ch-'a']->word);
        board[x][y] = '*';
        for(int d=0; d<4; d++){
            int nxtX = x + directions[d][0];
            int nxtY = y + directions[d][1];
            if(nxtX>=0 && nxtX<board.size() && nxtY>=0 && nxtY<board[0].size() && board[nxtX][nxtY]!='*')
                DFS(board, nxtX, nxtY, trie->child[ch-'a'], st);
        }
        board[x][y] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* trie = new TrieNode();
        for(int i=0; i<words.size(); i++){
            insert(trie, words[i]);
        }
        unordered_set<string> st;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                DFS(board, i, j, trie, st);
            }
        }
        vector<string> ans;
        for(string str: st){
            ans.push_back(str);
        }
        return ans;
    }
};
// @lc code=end

