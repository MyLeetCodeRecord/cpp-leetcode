/*
 * @lc app=leetcode.cn id=1706 lang=cpp
 *
 * [1706] 球会落何处
 */

// @lc code=start
class Solution {
public:
    int checkStart(vector<vector<int> > &grid, int c){
        int m = grid.size();
        int n = grid[0].size();
        int r = 0;
        while(r < m){
            int nextC = c+grid[r][c];
            if(nextC<0 || nextC>=n || grid[r][nextC] == -grid[r][c])
                return -1;
            c = nextC;
            r++;
        }
        return c;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(n, -1);
        for(int i=0; i<n; i++){
            ans[i] = checkStart(grid, i);
        }
        return ans;
    }
};
// @lc code=end

