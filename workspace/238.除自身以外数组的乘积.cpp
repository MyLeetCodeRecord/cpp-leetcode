/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    // 基础: left/right前缀乘积数组
    // O(1)空间: 第一轮先用ans记录left, 第二轮计算right的过程用变量记录
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        // ans数组首先作为left
        for(int i=1; i<n; i++){
            ans[i] = ans[i-1] * nums[i-1];
        }
        // ans数组作为左右乘积数组, 右侧乘积用变量表示
        int rightProduct = 1;
        for(int i=n-1; i>=0; i--){
            ans[i] = ans[i] * rightProduct;
            rightProduct *= nums[i];
        }
        return ans;
    }
};
// @lc code=end

