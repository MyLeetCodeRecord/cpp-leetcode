/*
 * @lc app=leetcode.cn id=1574 lang=cpp
 *
 * [1574] 删除最短的子数组使剩余数组有序
 */

// @lc code=start
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        // 最长后缀
        int r = n-1;
        while(r>0 && arr[r-1]<=arr[r])
            r--;
        // nums[r]: 最长后缀起点
        if(r==0)
            return 0;
        // (从左到右)枚举左端点, (从左到右)枚举右端点
        int ans = r;
        for(int l=0; l<=r; l++){
            if(l!=0 && arr[l]<arr[l-1])
                break;
            while(r<n && arr[r]<arr[l])
                r++;
            ans = min(ans, r-l-1);
        }
        return ans;
    }
};
// @lc code=end

