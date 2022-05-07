/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution {
private:
    int directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
public:
    // 多源BFS: 多个源点是0位置
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int> > ans(m, vector<int>(n, INT_MAX));
        queue<pair<int, int> > q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        // 按层BFS
        int step = 0;
        while(!q.empty()){
            int size = q.size();
            step++;
            for(int i=0; i<size; i++){
                pair<int, int> cur = q.front();
                q.pop();
                for(int d=0; d<4; d++){
                    int nextX = cur.first + directions[d][0];
                    int nextY = cur.second + directions[d][1];
                    if(nextX>=0 && nextX<m && nextY>=0 && nextY<n){
                        if(mat[nextX][nextY]==1){
                            mat[nextX][nextY] = 0;      // 距离可以通过为 1 的位置"传递"
                            q.push({nextX, nextY});
                            ans[nextX][nextY] = step;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

