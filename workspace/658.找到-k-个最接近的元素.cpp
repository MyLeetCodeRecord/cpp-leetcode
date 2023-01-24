/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 */

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l=0, r=n-1;
        while(l < r){
            int mid = (l+r)/2;
            if(arr[mid] < x)
                l = mid+1;
            else
                r = mid;
        }
        vector<int> ans;
        int i=l-1, j=l;
        while(ans.size() < k){
            int minVal = INT_MAX;
            if(i >= 0)
                minVal = min(minVal, abs(arr[i]-x));
            if(j < n)
                minVal = min(minVal, abs(arr[j]-x));
            if(i>=0 && minVal == abs(arr[i]-x))
                ans.push_back(arr[i--]);
            else
                ans.push_back(arr[j++]);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

