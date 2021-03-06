/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
private:
    int direction[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    int m, n;
public:
    vector<string> ans;
    string path;
    void backtrack(vector<vector<char> >& board, vector<vector<bool> >& visit, int row, int col, string word, int cur){
        if(board[row][col] != word[cur]){
            return ;
        }
        if(cur == word.size()-1){   // 注意如果用cur要放在cur判断后面, 建议直接用path.size()
            ans.push_back(path);
            return ;
        }
        visit[row][col] = true;
        for(int d=0; d<4; d++){
            int nextR = row + direction[d][0];
            int nextC = col + direction[d][1];
            if(nextR>=0 && nextR<m && nextC>=0 && nextC<n){
                if(visit[nextR][nextC] == false){   // 注意不能重复使用
                    path += board[nextR][nextC];
                    backtrack(board, visit, nextR, nextC, word, cur+1);
                    path = path.substr(0, path.size()-1);
                }
            }
        }
        visit[row][col] = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool> > visit(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                backtrack(board, visit, i, j, word, 0);
            }
        }
        return ans.size() > 0;
    }
};
// @lc code=end

