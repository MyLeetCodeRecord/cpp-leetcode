/*
 * @lc app=leetcode.cn id=845 lang=cpp
 *
 * [845] 数组中的最长山脉
 */

// @lc code=start
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n<=2)
            return 0;
        int ans = 0;
        for(int i=1; i<n-1; i++){
            // 枚举大于左右两侧的数, 以这个数为中心向两侧扩展
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
                int l = i-1, r = i+1;
                while(l-1>=0 && arr[l]>arr[l-1])
                    l--;
                while(r+1<n && arr[r]>arr[r+1])
                    r++;
                ans = max(ans, r-l+1);
            }
        }
        return ans;
    }
};
// @lc code=end

