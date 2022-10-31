##### 单调栈 - 左侧最近的更小元素
```CPP
#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

stack<int> sk;

int main(){
    int n, cur;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &cur);
        while(!sk.empty() && cur<=sk.top())
            sk.pop();
        if(!sk.empty())
            printf("%d ", sk.top());
        else
            printf("-1 ");
        sk.push_back(cur);
    }
    return 0;
}
```


##### LC739. 每日温度
```CPP
// 求左边的最近最大/最小 => ans[cur] = sk.top()
// 求右边的最近最大/最小 => ans[popped] = cur
vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> sk;
    int n = temperatures.size();
    vector<int> ans(n, 0);  // ans记录的idx下标间隔
    for(int i=0; i<n; i++){
        while(!sk.empty() && temperatures[i] > temperatures[sk.top()]){ // 注意ans要用的是idx下标
            ans[sk.top()] = i-sk.top();
            sk.pop();
        }
        sk.push(i);
    }
    return ans;
}
```