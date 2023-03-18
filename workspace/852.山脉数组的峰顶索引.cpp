/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
class Solution {
public:
    // "二分查找不一定是在有序数组上"
    // (1) 上升  1 - 3 - 5
    // (2) 山峰  3 - 5 - 4
    // (3) 下降  5 - 4 - 2
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 1, r = n-2;
        while(l < r){
            int mid = (l+r)/2;
            if(arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1])
                l = mid+1;
            else
                r = mid;
        }
        return l;
    }
};
// @lc code=end

