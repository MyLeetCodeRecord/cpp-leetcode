/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */

// @lc code=start
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    // DFS 将所有源节点入队列
                    DFS(grid, i, j);
                    // BFS 搜索最短路径
                    return BFS(grid);
                }
            }
        }
        return 0;
    }
private:
    int m, n;
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    // BFS不一定需要单源, 这里的queue通过DFS获得所有islandA中的点, 然后全部作为BFS的"第一层起点"
    queue<pair<int, int>> q;
    void DFS(vector<vector<int>> &grid, int i, int j) {
        if(i < 0 || j < 0 || i >= m || j >= m)
            return ;
        if(grid[i][j] != 1)
            return ;
        // 访问过的节点设为 -1，防止再次访问
        grid[i][j] = -1;
        q.push({i, j});
        DFS(grid, i + 1, j);
        DFS(grid, i - 1, j);
        DFS(grid, i, j + 1);
        DFS(grid, i, j - 1);
    }
    int BFS(vector<vector<int>> &grid) {
        int layer = 0;
        while(!q.empty()) {
            int qSize = q.size();
            for(int k = 0; k < qSize; k++) {
                auto p = q.front();
                q.pop();
                int x = p.first, y = p.second;
                for(int r = 0; r < 4; r++) {
                    int nx = x + dir[r][0], ny = y + dir[r][1]; 
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] == -1) {
                        continue;
                    }
                    if(grid[nx][ny] == 1) {
                        return layer;
                    } 
                    grid[nx][ny] = -1;
                    q.push({nx, ny});
                }        
            }
            layer++;    // layer++后置, 或者返回layer-1
        }
        return layer;
    }
};
// @lc code=end

