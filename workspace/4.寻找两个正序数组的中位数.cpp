/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
// https://leetcode.cn/problems/median-of-two-sorted-arrays/solutions/3983/shuang-zhi-zhen-by-powcai/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n)
            return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = m;
        while(l < r){
            int mid1 = (l+r)/2;
            int mid2 = (m+n+1)/2-mid1;
            if(nums1[mid1] < nums2[mid2-1]){
                l = mid1+1;
            }
            else{
                r = mid1;
            }
        }
        int cnt1 = l;
        int cnt2 = (m + n + 1)/2- l;
        const int c1 = max(cnt1 <= 0 ? INT_MIN:nums1[cnt1-1],
                           cnt2 <= 0 ? INT_MIN:nums2[cnt2-1]);
        const int c2 = min(cnt1 >= m ? INT_MAX: nums1[cnt1],
                           cnt2 >= n ? INT_MAX : nums2[cnt2]);
        return ((m+n)%2 == 1) ? c1 : (c1 + c2) * 0.5;
    }
};
// @lc code=end

