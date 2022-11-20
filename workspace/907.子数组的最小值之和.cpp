/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 */

// @lc code=start
class Solution {
public:
    // 要维护区间中的min, 说明比cur大的元素应该弹出去
    int sumSubarrayMins(vector<int>& arr) {
        long long ans = 0;
        // 首尾插入0, 不影响结果, 方便计算
        arr.insert(arr.begin(), 0);
        arr.push_back(0);
        int n = arr.size();
        stack<int> sk;
        for(int i=0; i<n; i++){
            while(!sk.empty() && arr[i] < arr[sk.top()]){
                // tmp: 以arr[mid]为min的区间范围, 栈中下一个元素 ~ i
                // 方案数 = 枚举起点、终点, 即(i-mid) * (mid-sk.top())
                // ans += tmp * arr[mid]
                int mid = sk.top();
                sk.pop();
                long long tmp = (i-mid) * (mid - sk.top());
                tmp %= 1000000007;
                ans += tmp * arr[mid];
                ans %= 1000000007;                
            }
            sk.push(i);
        }
        return (int)ans;
    }
};
// @lc code=end

