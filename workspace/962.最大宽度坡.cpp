/*
 * @lc app=leetcode.cn id=962 lang=cpp
 *
 * [962] 最大宽度坡
 */

// @lc code=start
class Solution {
public:
    // 单调栈
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> sk;  // 栈内单调递减
        for(int i=0; i<n; i++){
            if(sk.empty() || nums[i]<nums[sk.top()]){
                sk.push(i);
            }
        }
        int ans = 0;
        // 从右向左, 因此相邻的两个值, 如果不能对栈顶元素产生影响, 则右边的一定是更优解
        for(int i=n-1; i>=0; i--){
            while(!sk.empty() && nums[i]>=nums[sk.top()]){
                ans = max(ans, i-sk.top());
                sk.pop();
            }
        }
        return ans;
    }
    // 双关键字 sort
    int maxWidthRamp2(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos(n, 0);  // 用于双关键字排序
        for(int i=0; i<n; i++){
            pos[i] = i;
        }
        sort(pos.begin(), pos.end(), [&](int a, int b){
            if(nums[a] == nums[b])
                return pos[a] < pos[b];     // 第二关键字: 相等则保持相对顺序
            return nums[a] < nums[b];       // 第一关键字: 从小到大
        });
        int ans = 0;
        int minPos = n;
        for(int i=0; i<n; i++){
            ans = max(ans, pos[i]-minPos);
            minPos = min(minPos, pos[i]);
        }
        return ans;
    }
};
// @lc code=end

