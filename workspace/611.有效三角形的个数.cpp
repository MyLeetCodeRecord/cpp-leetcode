/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 */

// @lc code=start
class Solution {
public:
    // 最外层循环固定最长边
    // 内层两条边使用双指针
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i=2; i<nums.size(); i++){
            int left = 0;
            int right = i-1;
            while(left<right){
                if(nums[left]+nums[right] > nums[i]){
                    ans += (right-left);
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

