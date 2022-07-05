/*
 * @lc app=leetcode.cn id=1200 lang=cpp
 *
 * [1200] 最小绝对差
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int> > ans;
        int minDiff = arr.back() - arr[0];
        for(int i=1; i<arr.size(); i++){
            if(arr[i]-arr[i-1] < minDiff){
                ans.resize(0);
                minDiff = arr[i]-arr[i-1];
            }
            if(arr[i]-arr[i-1] == minDiff){
                ans.push_back({arr[i-1], arr[i]});
            }
        }
        return ans;
    }
};
// @lc code=end

