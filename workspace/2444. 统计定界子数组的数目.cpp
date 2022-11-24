class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int lastmin = -1;   // 最近的minK位置
        int lastmax = -1;   // 最近的maxK位置
        int illegal  = -1;  // 上一个不合法的位置
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == minK)
                lastmin = i;
            if(nums[i] == maxK)
                lastmax = i;
            if(nums[i]>maxK || nums[i]<minK){
                lastmin = -1;
                lastmax = -1;
                illegal = i;
            }
            if(lastmin!=-1 && lastmax!=-1)
                ans += (min(lastmin, lastmax) - illegal);  // 将lastmin和lastmax都包涵进来 => min
        }
        return ans;
    }
};