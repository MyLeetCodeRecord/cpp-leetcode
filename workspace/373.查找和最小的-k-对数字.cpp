/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的 K 对数字
 */

// @lc code=start
class Solution {
    typedef pair<int, int> PII;
public:
    // 多路归并, O(klogn)
    //      A[0]:   {A[0], B[0]}   {A[0], B[1]}   ...  {A[0], B[n-1]}
    //      ......
    //      A[m-1]: {A[m-1],B[0]}  {A[m-1],B[1]}  ...  {A[m-1],B[n-1]}
    vector<vector<int>> kSmallestPairs(vector<int>& A, vector<int>& B, int k) {
        int m = A.size();
        int n = B.size();
        priority_queue<pair<int, PII>, vector<pair<int, PII>>, greater<pair<int, PII>>> pq;
        // 注意: heap值初始化一行, 其它数对在「弹出时继续添加」
        for(int j=0; j<n; j++){
            PII cur = {0, j};
            pq.push({A[0]+B[j], cur});
        }
        vector<vector<int>> ans;
        while(k>0 && !pq.empty()){
            PII t = pq.top().second;
            pq.pop();
            ans.push_back({A[t.first], B[t.second]});
            // 继续添加其它数对
            if(t.first+1 < m){
                pq.push({A[t.first+1]+B[t.second], {t.first+1, t.second}});
            }
            k--;
        }
        return ans;
    }
};
// @lc code=end

