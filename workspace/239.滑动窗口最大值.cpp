/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 单调递增的双端队列
        deque<int> deq;
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(!deq.empty() && i-deq.front()+1 > k)
                deq.pop_front();
            while(!deq.empty() && nums[deq.back()]<=nums[i])
                deq.pop_back();
            deq.push_back(i);
            if(i >= k-1){
                ans.push_back(nums[deq.front()]);
            }
        }
        return ans;
    }
};
// @lc code=end

