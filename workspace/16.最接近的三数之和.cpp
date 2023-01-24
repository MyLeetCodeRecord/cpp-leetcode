/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3)
            return -1;
        int nearest = nums[0]+nums[1]+nums[2];
        //0. 先排序
        sort(nums.begin(),nums.end());
        //1. 固定 i ,双指针left & right
        for(int i=0;i<nums.size()-2;i++){
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                // 只需要返回sum,因此可以提前结束
                if(sum==target){
                    return target;
                }
                // 与target之差绝对值更小则更新nearest
                if(abs(sum-target) < abs(nearest - target)){
                    nearest = sum;
                }
                if(sum>target){
                    // 不考虑重复nums[left],在这里减少复杂度,在《三数之和》中保证不包含重复解
                    while(left<right && nums[right]==nums[right-1]){
                        right--;
                    }
                    right--;
                }
                if(sum<target){
                    // 不考虑重复nums[right]
                    while(left<right && nums[left]==nums[left+1]){
                        left++;
                    }
                    left++;
                }
            }
            // 不考虑从重复nums[i]
            while(i<nums.size()-2 && nums[i]==nums[i+1]){
                i++;
            }
        }
        return nearest;
    }
};
// @lc code=end

