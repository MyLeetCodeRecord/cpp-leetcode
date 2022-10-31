/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */

// @lc code=start
class Solution {
public:
    // 0~n-1: 从头向后迭代，区间最大值等于数组索引则得到一个所求区间
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        int localMax = 0;
        for(int i=0; i<n; i++){
            localMax = max(localMax, arr[i]);
            if(i==localMax){
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

