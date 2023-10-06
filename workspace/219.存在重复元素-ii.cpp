/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        k = min(k, (int)nums.size()-1);
        for(int i=0; i<=k; i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > 1)
                return true;
        }
        int l = 0, r = k+1;
        while(r < nums.size()){
            mp[nums[r++]]++;
            mp[nums[l++]]--;
            if(mp[nums[r-1]] > 1)
                return true;
        }
        return false;
    }
};
// @lc code=end

