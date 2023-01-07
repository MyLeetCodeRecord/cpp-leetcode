class Solution {
public:
    // 相向双指针
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int sum = nums[l] + nums[r];
        while(l < r){
            if(sum == target)
                return {l+1, r+1};
            if(sum < target)
                sum = sum-nums[l]+nums[++l];
            else
                sum = sum-nums[r]+nums[--r];
        }
        return {-1, -1};
    }
};