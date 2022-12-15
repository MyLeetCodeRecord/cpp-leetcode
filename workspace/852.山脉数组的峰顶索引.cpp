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
        // 否则要写「mid=(l+r+1)/2」, 不然会有「l=0, r=1」的case
        int l = 1;
        int r = arr.size()-2;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(arr[mid] > arr[mid-1])
                l = mid;
            else
                r = mid-1;
            // // 山峰
            // if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            //     return mid;
            // // 上升
            // if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1])
            //     l = mid+1;
            // // 下降
            // else if(arr[mid]<arr[mid-1] && arr[mid]>arr[mid+1])
            //     r = mid-1;
        }
        return l;
    }
};
// @lc code=end

