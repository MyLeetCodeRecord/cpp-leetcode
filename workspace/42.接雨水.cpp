/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    // 相向双指针: 空间复杂度 O(1)
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l = 0, r = n-1;
        int prefix = 0, suffix = 0;
        while(l < r){
            prefix = max(prefix, height[l]);
            suffix = max(suffix, height[r]);
            if(prefix < suffix){
                ans += min(prefix, suffix) - height[l];
                l++;
            }
            else{
                ans += min(prefix, suffix) - height[r];
                r--;
            }
        }
        return ans;
    }
    /*
    // 单调栈
    int trap(vector<int>& height) {
        stack<int> sk;  // 栈顶更小的单调栈
        int ans = 0;
        for(int i=0; i<height.size(); i++){
            // 相同 => 更新top下标
            if(!sk.empty() && height[i] == height[sk.top()]){
                sk.pop();
                sk.push(i);
                continue;   // 别push两次
            }
            // 栈顶元素更低
            while(!sk.empty() && height[i] > height[sk.top()]){
                int mid = sk.top(); // 底部
                sk.pop();
                if(!sk.empty()){
                    int h = min(height[sk.top()], height[i]) - height[mid]; // left和cur中更小的一个 - 底部高度
                    int w = i-sk.top()-1;   // cur-left
                    ans += w*h;
                }
            }
            sk.push(i);
        }
        return ans;
    }
    */
    /*
    // 动态规划 - 按列求: 左边的最高 & 右边的最高
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lHighest(n, height[0]);
        vector<int> rHighest(n, height.back());
        for(int i=1; i<n; i++){
            lHighest[i] = max(lHighest[i-1], height[i]);
        }
        for(int j=n-2; j>=0; j--){
            rHighest[j] = max(rHighest[j+1], height[j]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += min(lHighest[i], rHighest[i]) - height[i];
        }
        return ans;
    }
    */
};
// @lc code=end

