/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 */

// @lc code=start
class Solution {
public:
    // 二分解法
    int kthSmallest(vector<vector<int>>& matrix, int k){
        int n = matrix.size();
        int l = INT_MIN;
        int r = INT_MAX;
        while(l<r){
            int mid = (long long)l+r>>1;
            // 统计小于等于mid的元素个数
            int cnt = 0;
            int j = n-1;
            for(int i=0; i<n; i++){
                // !!! 每一行从上一行的结束位置继续向前遍历
                while(j>=0 && matrix[i][j]>mid)
                    j--;
                cnt += j+1;
            }
            if(cnt < k)
                l = mid+1;
            else
                r = mid;
        }
        return l;
    }
};
// @lc code=end

