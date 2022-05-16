/*
 * @lc app=leetcode.cn id=1162 lang=cpp
 *
 * [1162] 地图分析
 */

// @lc code=start
class Solution {
private:
    int directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = -1;
        queue<pair<int, int> > q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){    // 初始加入所有陆地
                    q.push({i, j});
                }
            }
        }
        int step = 0;
        while(!q.empty()){
            step++;
            int size = q.size();
            for(int i=0; i<size; i++){
                pair<int, int> cur = q.front();
                q.pop();
                for(int d=0; d<4; d++){
                    int nextX = cur.first + directions[d][0];
                    int nextY = cur.second + directions[d][1];
                    if(nextX>=0 && nextX<m && nextY>=0 && nextY<n){
                        if(grid[nextX][nextY]==0){
                            ans = step;
                            q.push({nextX, nextY});
                            grid[nextX][nextY] = -1;    // 标记为已访问过
                        }
                    } 
                }
            }
        }
        return ans;
    }
};
// @lc code=end

