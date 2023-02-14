/*
 * @lc app=leetcode.cn id=1124 lang=cpp
 *
 * [1124] 表现良好的最长时间段
 */

// @lc code=start
class Solution {
public:
    // LC962
    int getRemoteLarger(vector<int>& nums){
        int n = nums.size();
        stack<int> sk;  // 存一个「严格单调递减」序列的「下标」
        for(int i=1; i<=n; i++){
            if(sk.empty() || nums[i]<nums[sk.top()])
                sk.push(i);
        }
        int ans = 0;
        for(int i=n; i>=1; i--){
            while(!sk.empty() && nums[i]>nums[sk.top()]){
                ans = max(ans, i-sk.top());
                sk.pop();
            }
        }
        return ans;
    }
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int> prefixSum(n+1, 0);
        for(int i=0; i<n; i++){
            if(hours[i] > 8)
                hours[i] = 1;
            else
                hours[i] = -1;
            prefixSum[i+1] = prefixSum[i] + hours[i];
        }
        // 在prefixSum[]数组中找右侧最远更大的元素 => LC962
        return getRemoteLarger(prefixSum);
    }
};
// @lc code=end

