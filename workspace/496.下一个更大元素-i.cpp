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
        unordered_map<int, int> greater;    // 存元素值即可
        stack<int> sk;
        for(int i=0; i<nums2.size(); i++){
            while(!sk.empty() && sk.top()<nums2[i]){
                greater[sk.top()] = nums2[i];
                sk.pop();
            }
            sk.push(nums2[i]);
        }
        vector<int> ans(nums1.size(), -1);
        for(int i=0; i<nums1.size(); i++){
            if(greater.find(nums1[i])!=greater.end())
                ans[i] = greater[nums1[i]];
        }
        return ans;
    }
};
// @lc code=end

