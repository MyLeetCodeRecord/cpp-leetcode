/*
 * @lc app=leetcode.cn id=6052 lang=cpp
 *
 * [6052] 最小平均差
 */

// @lc code=start
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long> leftsum(nums.size(),nums[0]);
        vector<long long> rightsum(nums.size(),nums.back());
        for(int i=1;i<nums.size();i++){
            leftsum[i]=leftsum[i-1]+nums[i];
            rightsum[nums.size()-i-1] = rightsum[nums.size()-i]+nums[nums.size()-1-i];
        }
        int ans = INT_MAX;
        int pos = 0;
        for(int i=0;i<nums.size()-1;i++){
            int l=leftsum[i]/(i+1)- rightsum[i+1]/(nums.size()-i-1);
            if(abs(l)<ans){
                ans=min(ans,abs(l));
                pos=i;
            }
        }
        if(leftsum.back()/nums.size()<ans)
            pos=nums.size()-1;
        return pos;
    }
};
// @lc code=end

