/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lHeighest(height.size(), height[0]);
        vector<int> rHeighest(height.size(), height.back());
        for(int i=1; i<height.size(); i++){
            lHeighest[i] = max(height[i-1], lHeighest[i-1]);
        }
        for(int i=height.size()-2; i>=0; i--){
            rHeighest[i] = max(height[i+1], rHeighest[i+1]);
        }
        int ans = 0;
        for(int i=1; i<height.size()-1; i++){
            if(lHeighest[i] > height[i] && rHeighest[i] > height[i]){
                ans += min(lHeighest[i], rHeighest[i]) - height[i];
            }
        }
        return ans;
    }
};
// @lc code=end

