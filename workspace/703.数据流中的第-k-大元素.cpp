/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */

// @lc code=start
class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq; // 维护大小为k的小顶堆
    int sz;
public:
    KthLargest(int k, vector<int>& nums) {
        sz = k;
        for(int x: nums){
            pq.push(x);
            if(pq.size() > sz){
                pq.pop();
            }
        }
    }
    int add(int val) {
        pq.push(val);
        if(pq.size() > sz)
            pq.pop();
        return pq.top();
    }
};
// @lc code=end

