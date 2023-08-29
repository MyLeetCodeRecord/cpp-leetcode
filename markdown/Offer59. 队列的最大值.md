### queue / deque(单调队列)

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