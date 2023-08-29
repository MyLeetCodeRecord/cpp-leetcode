#### deque

##### 1. [滑动窗口的最大值](/workspace/239.%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC.cpp)

> 单调队列: 保持队列内元素单调性(递增/递减), 注意存储的是下标
> 
> “比你年轻(新加进队列的)又比你强(更满足条件), 你就永远没有出头之日”
> 
> - 维护: (连续)删除「队尾」大于新元素的值, 加入新元素
> - 查找min/max: 返回单调队列队首head (因为head并没有被过程淘汰
> 
> 复杂度: O(1)就可以取出min/max

```CPP
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // 单调递增的双端队列
    deque<int> deq;
    vector<int> ans;
    int n = nums.size();
    for(int i=0; i<n; i++){
        if(!deq.empty() && i-deq.front()+1 > k)
            deq.pop_front();
        while(!deq.empty() && nums[deq.back()]<=nums[i])
            deq.pop_back();
        deq.push_back(i);
        if(i >= k-1){
            ans.push_back(nums[deq.front()]);
        }
    }
    return ans;
}
```
https://leetcode.cn/problems/sliding-window-maximum/


##### 2. [剑指Offer59. 队列的最大值](/markdown/Offer59.%20%E9%98%9F%E5%88%97%E7%9A%84%E6%9C%80%E5%A4%A7%E5%80%BC.md)

```CPP
class MaxQueue {
private:
    queue<int> q;
    deque<int> deq;
public:
    MaxQueue() {
    }
    int max_value() {
        if(deq.empty())
            return -1;
        return deq.front();
    }
    void push_back(int value) {
        q.push(value);
        while(!deq.empty() && value>deq.back())
            deq.pop_back();
        deq.push_back(value);
    }
    int pop_front() {
        if(q.empty())
            return -1;
        int val = q.front();
        q.pop();
        if(deq.front()==val)
            deq.pop_front();
        return val;
    }
};
```
https://leetcode.cn/problems/dui-lie-de-zui-da-zhi-lcof/description/?envType=study-plan-v2&envId=coding-interviews