/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 */

// @lc code=start
class Solution {
public:
    int binary_search(vector<int>& arr, int target){
        int n = arr.size();
        int l = 0, r = n-1;
        while(l<r){
            int mid = (l+r)/2;
            if(arr[mid] < target)
                l = mid+1;
            else
                r = mid;
        }
        return l;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int j = binary_search(arr, x);
        int i = j - 1;
        cout<<i << " "<<j<<endl;
        vector<int> ans;
        while(ans.size() < k){
            if(i>=0 && (j>=n || x-arr[i] <= arr[j]-x)){
                ans.push_back(arr[i--]);
            }
            else if(j<n && (i<0 || x-arr[i] > arr[j]-x)){
                ans.push_back(arr[j++]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

