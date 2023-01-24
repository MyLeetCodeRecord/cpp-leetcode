class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = -1;
        int l=0, r=n-1;
        while(l < r){
            int sum = nums[l]+nums[r];
            if(sum >= k){
                r--;
            }
            else{
                ans = max(ans, sum);
                l++;
            }
        }
        return ans;
    }
};