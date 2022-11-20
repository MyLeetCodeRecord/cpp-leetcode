#### [单调栈](/markdown/%E4%B8%93%E9%A2%98%20-%20%E5%8D%95%E8%B0%83%E6%A0%88.md)
##### 单调栈 - 左侧最近的更小元素
```CPP
#include <cstdio>
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


##### LC496. 下一个更大元素I
```CPP
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> bigger(nums2.size(), -1);   // 存元素值即可
    stack<int> sk;
    for(int i=0; i<nums2.size(); i++){
        while(!sk.empty() && nums2[i]>nums2[sk.top()]){
            bigger[sk.top()] = nums2[i];
            sk.pop();
        }
        sk.push(i);
    }
    unordered_map<int, int> mp;
    for(int i=0; i<nums2.size(); i++){
        mp[nums2[i]] = i;
    }
    vector<int> ans(nums1.size(), -1);
    for(int i=0; i<nums1.size(); i++){
        ans[i] = bigger[mp[nums1[i]]];
    }
    return ans;
}
```