/*
 * @lc app=leetcode.cn id=992 lang=cpp
 *
 * [992] K 个不同整数的子数组
 */

// @lc code=start
class Solution {
public:
    int atMostKDistinct(vector<int>& nums, int k){
        int n = nums.size();
        int ans = 0;
        int l = 0, r = 0;
        // hash[] + cnt 起到 map 的作用, cnt和mp.size()相同
        vector<int> hash(20010, 0);
        int cnt = 0;
        while(r < n){
            if(hash[nums[r++]]++ == 0)
                cnt += 1;
            while(cnt > k){
                if(hash[nums[l++]]-- == 1)
                    cnt -= 1;
            }
            ans += r-l;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k-1);
    }
};
// @lc code=end

