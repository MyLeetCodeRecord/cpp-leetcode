/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return {};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int up = 0, down = m-1;
        int left = 0, right = n-1;
        while(true){
            for(int i=left; i<=right; i++){
                ans.push_back(matrix[up][i]);
            }
            if(++up > down)
                break;
            for(int j=up; j<=down; j++){
                ans.push_back(matrix[j][right]);
            }
            if(--right < left)
                break;
            for(int i=right; i>=left; i--){
                ans.push_back(matrix[down][i]);
            }
            if(--down < up)
                break;
            for(int j=down; j>=up; j--){
                ans.push_back(matrix[j][left]);
            }
            if(++left > right)
                break;
        }
        return ans;
    }
};
// @lc code=end

