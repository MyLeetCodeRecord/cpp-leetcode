/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1)
            return ;
        // 从后向前找到第一个"小值"
        int i = nums.size()-2;
        for(i=nums.size()-2; i>=0; i--){
            if(nums[i] < nums[i+1])
                break;
        }
        // 从后向前找到 nums[i] 后面用于交换的 nums[j], nums[j]是后面最小的大于nums[i]的值
        if(i >= 0){
            int j = nums.size()-1;
            while(j>=0 && nums[i]>=nums[j]){
                j--;
            }
            swap(nums[i], nums[j]); // nums[i]换成后面最小的更大值
        }
        // i 位置是最新被改变的值(变大为nums[j]), 将 i 位置后面按递增排序即可
        vector<int>::iterator it = nums.begin();
        for(int m=0;m<=i;m++)
            it++;
        sort(it,nums.end());
    }
};
// @lc code=end

