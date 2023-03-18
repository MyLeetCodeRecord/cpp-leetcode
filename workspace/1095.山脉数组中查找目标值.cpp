/*
 * @lc app=leetcode.cn id=1095 lang=cpp
 *
 * [1095] 山脉数组中查找目标值
 */

// @lc code=start
class Solution {
public:
    int binary_search_up(MountainArray &mountainArr, int l, int r, int target){
        while(l < r){
            int mid = (l+r)/2;
            int q_mid = mountainArr.get(mid);
            if(q_mid < target)
                l = mid+1;
            else
                r = mid;
        }
        return l;
    }
    int binary_search_down(MountainArray &mountainArr, int l, int r, int target){
        while(l < r){
            int mid = (l+r)/2;
            int q_mid = mountainArr.get(mid);
            if(q_mid > target)
                l = mid+1;
            else
                r = mid;
        }
        return l;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        // 1. 找到peak
        int l = 1, r = n-2;
        while(l < r){
            int mid = (l+r)/2;
            int q_mid = mountainArr.get(mid);
            int q_left = mountainArr.get(mid-1);
            int q_right = mountainArr.get(mid+1);
            if(q_left<q_mid && q_mid<q_right)
                l = mid+1;
            else
                r = mid;
        }
        int peak = l;
        // 找左侧升序数组
        l = binary_search_up(mountainArr, 0, peak, target);
        if(l<n && mountainArr.get(l)==target)
            return l;
        // 找右侧升序数组
        r = binary_search_down(mountainArr, peak, n-1, target);
        if(r>=0 && mountainArr.get(r)==target)
            return r;
        return -1;
    }
};
// @lc code=end

