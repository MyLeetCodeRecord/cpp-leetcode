/*
 * @lc app=leetcode.cn id=1806 lang=cpp
 *
 * [1806] 还原排列的最少操作步数
 */

// @lc code=start
class Solution {
public:
    // 找规律, 1归位所需的步数
    int reinitializePermutation(int n) {
        int step = 0;
        int i = 1;
        while(true){
            step++;
            if(i % 2 == 0)
                i = i/2;
            else
                i = n/2 + (i-1)/2;
            if(i==1)
                break;
        }
        return step;
    }
    // 纯模拟
    int reinitializePermutation2(int n) {
        vector<int> perm(n);
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            perm[i] = i;
        int step = 0;
        while(true){
            step++;
            for(int i=0; i<n; i++){
                if(i%2==0)
                    arr[i] = perm[i/2];
                else
                    arr[i] = perm[n/2 + (i-1)/2];
            }
            bool same = true;
            for(int i=0; i<n; i++){
                if(arr[i] != i)
                    same = false;
                perm[i] = arr[i];
            }
            if(same)
                return step;
        }
        return step;
    }
};
// @lc code=end

