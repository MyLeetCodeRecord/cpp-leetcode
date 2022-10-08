/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

// @lc code=start
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        // 记录nums2的元素位置
        vector<pair<int, int>> t;
        for (int i = 0; i < nums2.size(); i++){
            t.push_back({nums2[i], i});
        }
        sort(t.begin(), t.end());
        sort(nums1.begin(), nums1.end());

        int left = 0;
        int right = nums1.size() - 1;
        for (int n : nums1) {
            // 如果当前nums1最小的值没用了, 就直接与nums2中最大的匹配
            if (n <= t[left].first)
                ans[t[right--].second] = n;
            else
                ans[t[left++].second] = n;
        }
        return ans;
    }
};
// @lc code=end

