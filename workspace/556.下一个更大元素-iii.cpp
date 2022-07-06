/*
 * @lc app=leetcode.cn id=556 lang=cpp
 *
 * [556] 下一个更大元素 III
 */

// @lc code=start
class Solution {
public:
    bool nextPermutation(vector<int>& nums) {
        if(nums.size()<=1)
            return false;
        bool exist = false;
        // 从后向前找到第一个"小值"
        int i = nums.size()-2;
        for(i=nums.size()-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                exist = true;
                break;
            }
        }
        if(!exist)
            return false;
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
        sort(it, nums.end());   // 从小到大排列
        return true;
    }
    int nextGreaterElement(int n) {
        string str = to_string(n);
        vector<int> nums;
        for(int i=0; i<str.size(); i++){
            nums.push_back(str[i]-'0');
        }
        bool exist = nextPermutation(nums);
        if(!exist)
            return -1;
        long long ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans = ans*10+nums[i];
        }
        return (ans>INT_MAX) ? -1 : ans;
    }
};
// @lc code=end

