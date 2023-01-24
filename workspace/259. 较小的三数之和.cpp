class Solution {
public:
    // 计数的是下标三元组, 因此不需要去重
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i=0; i+2<n; i++){
            int l=i+1, r=n-1;
            while(l < r){
                int sum = nums[i]+nums[l]+nums[r];
                if(sum >= target){
                    r--;
                }
                else{
                    // 相当于固定l, r可取的值为(l+1,r]
                    ans += (r-l);
                    l++;
                }
            }
        }
        return ans;
    }
};