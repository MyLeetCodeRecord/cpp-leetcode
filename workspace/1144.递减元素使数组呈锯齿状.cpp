/*
 * @lc app=leetcode.cn id=1144 lang=cpp
 *
 * [1144] 递减元素使数组呈锯齿状
 */

// @lc code=start
class Solution {
public:
    // 贪心: 枚举两种方案
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size();
        int evenCost = 0;
        int oddCost = 0;
        vector<int> minNeighbor(n);
        for(int i=0; i<n; i++){
            if(i % 2 == 1)
                continue;
            int minNeighbor = INT_MAX;
            if(i-1>=0)
                minNeighbor = min(minNeighbor, nums[i-1]);
            if(i+1<n)
                minNeighbor = min(minNeighbor, nums[i+1]);
            evenCost += max(nums[i]-(minNeighbor-1), 0);
        }
        for(int i=0; i<n; i++){
            if(i % 2 == 0)
                continue;
            int minNeighbor = INT_MAX;
            if(i-1>=0)
                minNeighbor = min(minNeighbor, nums[i-1]);
            if(i+1<n)
                minNeighbor = min(minNeighbor, nums[i+1]);
            oddCost += max(nums[i]-(minNeighbor-1), 0);
        }
        return min(oddCost, evenCost);
    }
};
// @lc code=end

