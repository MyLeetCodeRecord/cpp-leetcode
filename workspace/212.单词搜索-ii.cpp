/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
struct TrieNode{
    TrieNode* child[26];
    string word;    // 题目要的是string, 不是bool, word.size()>0也可以起到isEnd的作用
    TrieNode(){
        for(int i=0; i<26; i++)
            child[i] = NULL;
        word = "";
    }
};
class Solution {
private:
    TrieNode* trie;
    int directions[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
public:
    void add(string word){
        TrieNode* t = trie;
        for(char ch : word){
            if(t->child[ch-'a'] == NULL){
                t->child[ch-'a'] = new TrieNode();
            }
            t = t->child[ch-'a'];
        }
        t->word = word;
    }
    void dfs_search(TrieNode* t, vector<vector<char>>& board, int r, int c, unordered_set<string>& ans_set){
        // 标记, 避免重复使用同一个格子
        char ch = board[r][c];
        // root没有值, 元素是用“边”表示和存储的
        if(t->child[ch-'a']==NULL)
            return ;
        // 到达了一个完整单词 => 存入set
        if(t->child[ch-'a']->word.size() != 0){
            ans_set.insert(t->child[ch-'a']->word);
        }
        board[r][c] = '#';
        for(int d=0; d<4; d++){
            int nextX = r + directions[d][0];
            int nextY = c + directions[d][1];
            if(nextX>=0 && nextX<board.size() && nextY>=0 && nextY<board[0].size()){
                if(board[nextX][nextY] != '#'){
                    // 字符串的推进是通过Trie实现的
                    dfs_search(t->child[ch-'a'], board, nextX, nextY, ans_set);
                }
            }
        }
        //回溯, 恢复现场
        board[r][c] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // 建一棵Trie, 存入words列表
        trie = new TrieNode();
        for(string w : words){
            add(w);
        }
        // 使用set保存
        unordered_set<string> ans_set;
        // 设置在board上搜索的不同起点
        for(int r=0; r<board.size(); r++){
            for(int c=0; c<board[0].size(); c++){
                dfs_search(trie, board, r, c, ans_set);
            }
        }
        // 转换成vector
        vector<string> ans;
        for(string str: ans_set){
            ans.push_back(str);
        }
        return ans;
    }
};
// @lc code=end

