/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
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
    // 动态规划 - 按列求: 左边的最高 & 右边的最高
    // int trap(vector<int>& height) {
    //     vector<int> lHighest(height.size(), height[0]);
    //     vector<int> rHighest(height.size(), height.back());
    //     for(int i=1; i<height.size(); i++){
    //         lHighest[i] = max(height[i-1], lHighest[i-1]);
    //     }
    //     for(int i=height.size()-2; i>=0; i--){
    //         rHighest[i] = max(height[i+1], rHighest[i+1]);
    //     }
    //     int ans = 0;
    //     for(int i=1; i<height.size()-1; i++){
    //         if(lHighest[i] > height[i] && rHighest[i] > height[i]){
    //             ans += min(lHighest[i], rHighest[i]) - height[i];
    //         }
    //     }
    //     return ans;
    // }
};
// @lc code=end

