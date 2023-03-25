/*
 * @lc app=leetcode.cn id=1630 lang=cpp
 *
 * [1630] 等差子数组
 */

// @lc code=start
class Solution {
public:
    //n, m<=500   暴力
    bool isArithmeticSeries(vector<int>& subArray){
        sort(subArray.begin(), subArray.end());
        int diff = subArray[1] - subArray[0];
        for (int i=2; i < subArray.size(); i++)
            if (subArray[i]-subArray[i - 1] != diff)
                return false;
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l. size();
        vector<bool> ans;
        for(int i=0; i<m; i++){
            vector<int> subArray;
            for(int j=l[i]; j<=r[i]; j++){
                subArray.push_back(nums[j]);
            }
            ans.push_back(isArithmeticSeries(subArray));
        }
        return ans;
    }
};
// @lc code=end

