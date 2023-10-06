/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    // 先对第一列进行二分查找, 找到最后一个小于等于target的matrix[x][0]
    // 然后对这一行进行二分查找
    // -> O(logm + logn)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int r = m-1;
        while(l < r){
            int mid = (l+r+1)/2;
            if(matrix[mid][0] == target)
                return true;
            if(matrix[mid][0] > target)
                r = mid-1;
            else
                l = mid;
        }
        // 对matrix[l]这一行进行二分查找
        vector<int> line = matrix[l];
        l = 0;
        r = n-1;
        while(l < r){
            int mid = (l+r)/2;
            if(line[mid] < target)
                l = mid+1;
            else
                r = mid;
        }
        return (line[l] == target);
    }
    // 拉伸为一维数组 -> log(m*n)
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int m = matrix.size();      // 3
    //     int n = matrix[0].size();   // 4
    //     int l = 0;
    //     int r = m*n-1;
    //     while(l < r){
    //         int mid = (l+r)/2;
    //         // 1d -> 2d
    //         int row = mid / n;
    //         int col = mid % n;
    //         if(matrix[row][col] == target)
    //             return true;
    //         else if(matrix[row][col] < target)
    //             l = mid + 1;
    //         else
    //             r = mid;
    //     }
    //     // 有可能没进去上面的循环 e.g. [[1]]  1
    //     int row = l / n;
    //     int col = l % n;
    //     return matrix[row][col]==target;
    // }
};
// @lc code=end

