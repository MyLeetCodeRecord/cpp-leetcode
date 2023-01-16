/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // zero左侧的都是0, two右侧的都是2
        int zero = 0;
        int two = nums.size()-1;
        for(int i=0; i<=two; ){
            if(nums[i]==1){
                i++;
            }
            else if(nums[i]==0){
                swap(nums[zero], nums[i]);
                zero++;
                i++;
            }
            else if(nums[i]==2){
                swap(nums[two], nums[i]);
                two--;
                // 没有i++
            }
        }
    }
};
// @lc code=end

