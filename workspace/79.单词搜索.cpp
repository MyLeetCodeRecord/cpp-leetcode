/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    int direction[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    bool backtrack(vector<vector<char>>& board, int r, int c, string& word, int cur){
        if(cur == word.size())
            return true;
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) 
            return false;
        if(board[r][c] != word[cur])
            return false;
        board[r][c] = '.';
        for(int d=0; d<4; d++){
            int x = r + direction[d][0];
            int y = c + direction[d][1];
            // 如果在这里就check x,y合法性的话, [["a"]] "a" 这种case过不了
            // 或者可以if(board[r][c]!=word[cur]) return false; 然后if(cur==word.size()-1) return true;
            if(backtrack(board, x, y, word, cur+1))
                return true;
        }
        board[r][c] = word[cur];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(backtrack(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end

