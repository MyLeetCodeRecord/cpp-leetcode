##### 1. 区间选点 / 最大不相交区间数量

```CPP
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef pair<int, int> PII;

bool static cmp(PII l, PII r){
    return l.second < r.second;
}
const int N = 100010;
PII intervals[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &intervals[i].first, &intervals[i].second);
    }
    sort(intervals.begin(), intervals.end(), cmp);
    int cnt = 0;
    int ed = INT_MIN;
    for(int i=0; i<intervals.size(); i++){
        if(intervals[i].first > ed){
            ed = intervals[i].second;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
```

##### 2. 区间分组

```CPP
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 100010;
PII intervals[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0 i<n; i++){
        scanf("%d %d", &intervals[i].first,intervals[i].second);
    }
    sort(intervals,intervals+n);
    priority_queue<int, vector<int>, greater<int>> maxR_pq;
    for(int i=0; i<n; i++){
        PII cur = intervals[i];
        if(!maxR_pq.empty() && cur.first > maxR_pq.top()){
            heap.pop();
            heap.push(cur.second);
        }
        else
            heap.push(cur.second);
    }
    cout<<heap.size()<<endl;
    return 0;
}
```