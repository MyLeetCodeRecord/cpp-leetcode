/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
class MedianFinder {
    priority_queue<int, vector<int>, less<int>> leftPq;     // 更小的一边, 大顶堆
    priority_queue<int, vector<int>, greater<int>> rightPq;    // 更大的一边, 小顶堆
public:
    MedianFinder() {
    }
    void addNum(int num) {
        if(leftPq.empty() || num < leftPq.top()){
            leftPq.push(num);
            if(leftPq.size()-rightPq.size()>1){
                rightPq.push(leftPq.top());
                leftPq.pop();
            }
        }
        else{
            rightPq.push(num);
            if(rightPq.size() > leftPq.size()){
                leftPq.push(rightPq.top());
                rightPq.pop();
            }
        }
        
    }
    double findMedian() {
        if(leftPq.size()>rightPq.size())
            return leftPq.top();
        else
            return (double)(leftPq.top()+rightPq.top())/2;
    }
};
// @lc code=end

