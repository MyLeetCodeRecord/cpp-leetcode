/*
 * @lc app=leetcode.cn id=2032 lang=cpp
 *
 * [2032] 至少在两个数组中出现的值
 */

// @lc code=start
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        // 000 001 010 100
        // 110 101 011
        // 111
        unordered_map<int, int> mp;
        for(int x: nums1){
            mp[x] |= 1;
        }
        for(int x: nums2){
            mp[x] |= 2;
        }
        for(int x: nums3){
            mp[x] |= 4;
        }
        vector<int> ans;
        for(auto& [k, v]: mp){
            int oneCnt = (v&1) + ((v>>1)&1) + ((v>>2)&1);
            if(oneCnt>=2)
                ans.push_back(k);
        }
        return ans;
    }
};
// @lc code=end

