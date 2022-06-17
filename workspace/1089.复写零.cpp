/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 *
 * [1089] 复写零
 */

// @lc code=start
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int zeroCnt = 0;
        for(int a: arr){
            if(a==0)
                zeroCnt++;
        }
        for(int i=arr.size()-1; i>=0; i--){
            if(arr[i] == 0){
                if(i+zeroCnt < arr.size()){
                    arr[i+zeroCnt] = 0;
                }
                zeroCnt--;
            }
            if(i+zeroCnt < arr.size())
                arr[i+zeroCnt] = arr[i];
        }
    }
};
// @lc code=end

