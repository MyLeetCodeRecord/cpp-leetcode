/*
 * @lc app=leetcode.cn id=1252 lang=cpp
 *
 * [1252] 奇数值单元格的数目
 */

// @lc code=start
class Solution {
public:
    // 问"奇数/偶数"如何, 很可能用到"抵消"
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> rowCnt(m, 0);
        vector<int> colCnt(n, 0);
        for(vector<int> vi: indices){
            rowCnt[vi[0]] = (rowCnt[vi[0]]+1) % 2;
            colCnt[vi[1]] = (colCnt[vi[1]]+1) % 2;
        }
        // 但凡是行&列, 一定有且只有一个交点(重叠一个格)
        int rcnt = 0;
        for(int i=0; i<m; i++)
            rcnt += (rowCnt[i]==1);
        int ccnt = 0;
        for(int j=0; j<n; j++)
            ccnt += (colCnt[j]==1);
        return rcnt * n + ccnt * m - 2 * rcnt*ccnt;
    }
};
// @lc code=end

