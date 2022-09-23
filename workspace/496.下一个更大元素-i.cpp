/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    // nums1是nums2的子集, 说明nums1可以看作是一个查询列表, 只需要建立一个map在nums2中找到对应位置即可
    stack<int> sk;
    map<int, int> mp;
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> bigger(nums2.size(), -1);
        for(int i=0; i<nums2.size(); i++){
            mp[nums2[i]] = i;
            while(!sk.empty() && nums2[i] > nums2[sk.top()]){
                bigger[sk.top()] = i;
                sk.pop();
            }
            sk.push(i);
        }
        vector<int> ans(nums1.size(), -1);
        for(int i=0; i<nums1.size(); i++){
            if(bigger[mp[nums1[i]]]!=-1)
                ans[i] = nums2[bigger[mp[nums1[i]]]];
        }
        return ans;
    }
};
// @lc code=end

