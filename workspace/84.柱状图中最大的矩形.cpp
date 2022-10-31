/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    // 单调栈, 找左、右比mid更高的区间
    // 以heights[mid]为矩形高, 即低点
    int largestRectangleArea(vector<int>& heights) {
        // 数组头尾加上0, 方便统一处理
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        int ans = 0;

        stack<int> sk;  // 单调递增的栈
        sk.push(0);
        for(int i=1; i<heights.size(); i++){
            // 更新下标
            if(heights[i] == heights[sk.top()]){
                sk.pop();
                sk.push(i);
            }
            // cur更高 => push
            else if(heights[i] > heights[sk.top()]){
                sk.push(i);
            }
            // cur更低 => 
            else{
                while(!sk.empty() && heights[i]<heights[sk.top()]){
                    int mid = sk.top();
                    sk.pop();
                    if(!sk.empty()){
                        int h = heights[mid];
                        int w = i-sk.top()-1;
                        ans = max(ans, h*w);
                    }
                }
                sk.push(i);
            }
        }
        return ans;
    }
};
// @lc code=end

