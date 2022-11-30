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

bool static cmp(PII l, PII r){
    return l.second < r.second;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &intervals[i].first, &intervals[i].second);
    }
    sort(intervals, intervals+n, cmp);
    int ed = INT_MIN;
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(intervals[i].first > ed){
            cnt++;
            ed = intervals[i].second;
        }
    }
    cout<<ed<<endl;
    return 0;
}
```

##### LC435. 无重叠区间
```CPP
// 按右边界排序
bool static cmp(vector<int> &l, vector<int> &r){
    return l[1] < r[1];
}
int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), cmp);
    int end = points[0][1];
    int cnt = 1;
    for(int i=0; i<points.size(); i++){
        if(points[i][0] > end){
            end = points[i][1];
            cnt++;
        }
    }
    return cnt;
}
```

##### LC452. 用最少的箭引爆气球
```CPP
bool static cmp(vector<int> &l, vector<int> &r){
    return l[1] < r[1];
}
int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), cmp);
    long long ed = 2*INT_MIN;
    for(int i=0; i<intervals.size(); i++){
        if(intervals[i][0] > ed){
            cnt++;
            ed = intervals[i][1];
        }
    }
    return cnt;
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
    sort(intervals, intervals + n);
    priority_queue<int, vector<int>, greater<int>> maxR;
    for(int i=0; i<n; i++){
        if(maxR.empty() || intervals[i].first <= maxR.top()){    // 包括端点, 没有交集
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

##### Acwing111. 畜栏预定 - 要返回分组id
```CPP
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> PII;

const int N = 50010;
pair<PII, int> intervals[N]; // 为啥要多存一维int => 因为排序后顺序是乱序的
int ans[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &intervals[i].first.first, &intervals[i].first.second);
        intervals[i].second = i;
    }
    sort(intervals, intervals+n);
    priority_queue<PII, vector<PII>, greater<PII>> maxR;    // first是排序依据, 所以存右端点; second存group_id
    for(int i=0; i<n; i++){
        PII cur = intervals[i].first;
        if(maxR.empty() || cur.first <= maxR.top().first){
            ans[intervals[i].second] = maxR.size()+1;
            maxR.push({cur.second, maxR.size()+1});
        }
        else{
            int cur_group = maxR.top().second;
            maxR.pop();
            ans[intervals[i].second] = cur_group;
            maxR.push({cur.second, cur_group});
        }
    }
    printf("%d\n", (int)maxR.size());
    for(int i=0; i<n; i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}
```

##### 3. 区间覆盖
```CPP
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

const int N = 100010;
PII intervals[N];

int main(){
    int n, start, ed;
    scanf("%d %d", &start, &ed);
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &intervals[i].first, &intervals[i].second);
    }
    sort(intervals.begin(), intervals.end());
    int cover = start;
    int cnt = 0;
    bool exist = false;
    for(int i=0; i<n; i++){
        int j = i;
        int localCover = intervals[i].second;
        while(j<n && intervals[i].first <= cover){
            localCover = max(localCover, intervals[i].second);
            j++;
        }
        if(localCover >= ed){
            exist = true;
            break;
        }
        if(localCover <= cover){
            exist = false;
            break;
        }
        cover = localCover;
        i = j - 1;
    }
    if(exist)
        printf("%d\n", cnt);
    else
        printf("-1");
    return 0;
}
```

##### LC55. 跳跃游戏
```CPP
bool canJump(vector<int>& nums) {
    int cover = nums[0];
    for(int i=0; i<=cover; i++){
        if(cover >= nums.size()-1)
            return true;
        cover = max(cover, i+nums[i]);
    }
    return false;
}
```

##### LC45. 跳跃游戏II
```CPP
int jump(vector<int>& nums) {
    int step = 0;
    int cover = 0;
    int localCover = INT_MIN;
    for(int i=0; i<=cover; i++){
        if(cover >= nums.size()-1)
            return step;
        // 不超过cover的localCover没有必要更新
        if(i+nums[i] > cover)
            localCover = max(localCover, i+nums[i]);
        // 没办法继续进行了
        if(i==cover && localCover > cover){
            cover = localCover;
            step++;
        }
    }
    return step;
}
```

##### LC763. 划分字母区间
```CPP
vector<int> partitionLabels(string s) {
    vector<int> ans;
    vector<int> lastPos(26, INT_MAX);
    for(int i=0; i<s.size(); i++){
        lastPos[s[i]-'a'] = i;
    }
    int cover = 0;
    int last = -1;
    // cover是至少要达到的距离, 每次i==cover后可以截断一次, cover要根据下一个子串重置
    for(int i=0; i<=cover; i++){
        // 根据lastPos扩大cover
        cover = max(cover, lastPos[s[i]-'a']);
        if(i==cover){
            ans.push_back(i-last);
            last = i;
            // 如果没到末尾, 需要重置cover, 继续遍历下个子串, 或者外层循环直接用s.size()也可以
            if(i!=s.size()-1)
                cover = lastPos[s[i+1]-'a'];
        }
    }
    return ans;
}
```

##### 4. 合并果子(任意) - `Huffman树`
```CPP
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        pq.push(x);
    }
    long long ans = 0;
    while(pq.size() >= 2){
        int a = pq.top();   pq.pop();
        int b = pq.top();   pq.pop();
        pq.push(a+b);
        ans += (a+b);
    }
    cout<<ans<<endl;
    return 0;
}
```

##### 5. 合并石子(相邻) - `dp`
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int stones[N];
int prefixSum[N];
int dp[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &stones[i]);
        prefixSum[i] = prefixSum[i-1] + stones[i];
    }
    for(int len=2; len<=n; len++){
        for(int i=1; i+len-1<=n; i++){
            int j = i+len-1;
            dp[i][j] = 0x3f3f3f3f;
            for(int k=i; k<j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + (prefixSum[j]-prefixSum[i-1]));
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}
```

##### 6. 排队打水
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
    long long sum = 0;
    for(int i=0; i<n; i++){
        sum += (times[i] * (n-i-1));
    }
    cout<<sum<<endl;
    return 0;
}
```

##### 7. 货仓选址
```CPP
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    long long ans = 0;
    int base = pos[n/2];
    cout<<base<<endl;
    for(int pos: a){
        ans += abs(base - pos);
    }
    cout<<ans<<endl;
    return 0;
}
```

##### LC2448. 使数组相等的最小开销 
```CPP
long long minCost(vector<int>& nums, vector<int>& cost) {
    int n = nums.size();
    // Step1: 排序
    vector<vector<int>> pairs;   // 为了排序对齐
    for(int i=0; i<n; i++){
        pairs.push_back({nums[i], cost[i]});
    }
    sort(pairs.begin(), pairs.end());
    // Step2: 计算"总个数", 中位数贪心
    long long totalCost = 0;
    for(int i=0; i<n; i++){
        totalCost += cost[i];
    }
    long long mid = (totalCost+1)/2;
    long long idx = 0;
    for(int i=0; i<n; i++){
        idx += pairs[i][1];
        if(idx >= mid){     // 找到中位数
            long long ans = 0;
            for(int j=0; j<n; j++){     // 计算中位数处的开销作为ans返回
                ans += (long long)abs(pairs[j][0]-pairs[i][0]) * pairs[j][1];
            }
            return ans;
        }
    }
    return 0;
}
```

##### 8. 耍杂技的牛
```CPP
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef pair<int, int> PII;

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
    long long ans = INT_MIN;
    long long cumW = 0;
    // 从顶部开始遍历
    for(int i=0; i<n; i++){
        int w = cows[i].second;
        int s = cows[i].first - w;
        ans = max(ans, cumW-s);
        cumW += w;
    }
    cout<<ans<<endl;
    return 0;
}
```