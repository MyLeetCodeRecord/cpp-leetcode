/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    // 原地 二分法
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m*n;
        while(left < right){
            int mid = (right-left)/2 + left;
            int row = mid / n;
            int col = mid % n;
            // cout<<mid <<" => ("<<row<<","<<col<<") => "<<matrix[row][col]<<endl;
            int cur = matrix[row][col];
            if(cur == target){
                return true;
            }
            else if(cur < target){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        return false;
    }
};
// @lc code=end

