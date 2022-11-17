##### 1. 区间选点
```CPP
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 100010;
PII intervals[N];

bool static cmp(PII &l, PII &r){
    return l.second < r.second;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &intervals[i].first, &intervals[i].second);
    }
    sort(inervals, interval+n, cmp);
    int cnt = 0;
    int ed = INT_MIN;
    for(int i=0; i<n; i++){
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
    for(int i=0; i<n; i++){
        scanf("%d %d", &intervals[i].first, &intervals[i].second);
    }
    sort(intervals, intervals + n);  // 按开始时间排序
    priority_queue<int, vector<int>, greater<int>> maxR;
    for(int i=0; i<n; i++){
        if(maxR.empty() || intervals[i].first <= maxR.top()){
            maxR.push(intervals[i].second);
        }
        else{
            maxR.pop();
            maxR.push(intervals[i].second);
        }
    }
    cout<<maxR.size()<<endl;
    return 0;
}
```

##### 3. 畜栏预定
```CPP
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 50010;
pair<PII, int> intervals[N];
int id[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &intervals[i].first.first, &intervals[i].first.second);
        intervals[i].second = i;
    }
    sort(intervals, intervals + n);  // 按开始时间排序
    priority_queue<PII, vector<PII>, greater<PII>> maxR;    // maxR - stallID
    for(int i=0; i<n; i++){
        PII curInterval = intervals[i].first;
        if(maxR.empty() || curInterval.first <= maxR.top().first){
            PII stall = {curInterval.second, maxR.size()+1};
            maxR.push(stall);
            id[intervals[i].second] = stall.second;
        }
        else{
            int stallID = maxR.top().second;
            maxR.pop();
            maxR.push({curInterval.second, stallID});
            id[intervals[i].second] = stallID;
        }
    }
    printf("%d\n", maxR.size());
    for(int i=0; i<n; i++){
        printf("%d\n", id[i]);
    }
    return 0;
}
```

##### 4. 区间覆盖
```CPP
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef pair<int,int> PII;
const int N = 100010;
PII intervals[N];

int main(){
    int start, ed, n;
    scanf("%d %d", &start, &ed);
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &intervals[i].first, &intervals[i].second);
    }
    sort(intervals, intervals+n);
    bool exist = false;
    int cnt = 0;
    for(int i=0; i<n; i++){
        int j = i;
        int localCover = INT_MIN;
        while(j < n && intervals[j].first<=start){
            localCover = max(localCover, intervals[j].second);
            j++;
        }
        if(localCover < start){
            cnt = -1;
            break;
        }
        else{
            cnt++;
            start = localCover;
            if(start >= ed){
                exist = true;
                break;
            }
        }
        i = j-1;
    }
    if(exist)
        cout<<cnt<<endl;
    else
        cout<<"-1"<<endl;
    return 0;
}
```

##### 5. 排队打水

```CPP
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int times[N];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &times[i]);
    }
    sort(times, times+n);
    long long ans = 0;
    for(int i=0; i<n; i++){
        ans += (n-i-1) * times[i];
    }
    cout<<ans<<endl;
    return 0;
}
```

##### 6. 货仓选址 - 中位数贪心
```CPP
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int stores[N];
int main(){
    for(int i=0; i<n; i++){
        scanf("%d", &stores[i]);
    }
    sort(stores, stores+n);
    long long ans = 0;
    int base = stores[n/2];
    for(int i=0; i<n; i++){
        ans += abs(stores[i]-base);
    }
    cout<<ans<<endl;
    return 0;
}
```

##### 7. 耍杂技的牛
```CPP
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef pair<int,int> PII;

const int N = 50010;
PII cows[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int w, s;
        scanf("%d %d", &w, &s);
        cows[i] = {w+s, w};
    }
    sort(cows, cows+n);
    int ans = INT_MIN;    // 最大危险值
    int sumWeight = 0;
    for(int i=0; i<n; i++){
        int w = cows[i].second;
        int s = cows[i].first - w;
        ans = max(ans, sumWeight-s);
        sumWeight += cows[i].second;
    }
    cout<<ans<<endl;
    return 0;
}
```