/*
 * @lc app=leetcode.cn id=1053 lang=cpp
 *
 * [1053] 交换一次的先前排列
 */

// @lc code=start
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int i = n-2;
        for(i=n-2; i>=0; i--){
            if(arr[i] > arr[i+1])
                break;
        }
        // 不存在, 已经是升序序列, 即最小值
        if(i < 0)
            return arr;
        // 与i后面, 最大的, 比arr[i]小的值进行一次交换
        int maxSmaller = i+1;
        for(int j=i+1; j<n; j++){
            // [3,1,1,3], 3要与第一次1交换, 因此这里从前向后遍历 & 取大于号
            if(arr[j] < arr[i] && arr[j] > arr[maxSmaller]){
                maxSmaller = j;
            }
        }
        swap(arr[i], arr[maxSmaller]);
        return arr;
    }
};
// @lc code=end

