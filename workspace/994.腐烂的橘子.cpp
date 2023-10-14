/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
    typedef pair<int, int> PII;
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int BFS(vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        queue<PII> q;
        int fresh = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2)
                    q.push({i, j});
                if(grid[i][j]==1)
                    fresh++;
            }
        }
        int layer = 0;
        while(fresh>0 && !q.empty()){
            layer++;
            int sz = q.size();
            for(int i=0; i<sz; i++){
                PII cur = q.front();
                q.pop();
                for(int d=0; d<4; d++){
                    int nx = cur.first + directions[d][0];
                    int ny = cur.second + directions[d][1];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                    }
                }
            }
        }
        return (fresh==0) ? layer : -1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        return BFS(grid);
    }
};
// @lc code=end

