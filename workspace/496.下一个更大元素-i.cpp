/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    // nums1是nums2的子集, 说明nums1可以看作是一个query列表, 只需要建立一个map在nums2中找到对应位置即可
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[nums2[i]] = i;
        }
        stack<int> sk;
        vector<int> bigger(n, -1);
        for(int i=0; i<n; i++){
            int cur = nums2[i];
            while(!sk.empty() && cur>nums2[sk.top()]){
                bigger[sk.top()] = cur;
                sk.pop();
            }
            sk.push(i);
        }
        vector<int> ans(m, -1);
        for(int i=0; i<m; i++){
            ans[i] = bigger[mp[nums1[i]]];
        }
        return ans;
    }
};
// @lc code=end

