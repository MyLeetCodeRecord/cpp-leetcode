#### Biweekly 101

##### 1. [2605. 从两个数字数组里生成最小数字](https://leetcode.cn/problems/form-smallest-number-from-two-digit-arrays/): `hash`

```CPP
int minNumber(vector<int>& nums1, vector<int>& nums2) {
    vector<bool> mp1(10, false);
    vector<bool> mp2(10, false);
    int min1 = 10, min2 = 10;
    for(int x: nums1){
        mp1[x] = true;
        min1 = min(min1, x);            
    }
    for(int x: nums2){
        mp2[x] = true;
        min2 = min(min2, x);            
    }
    for(int i=1; i<=9; i++){
        if(mp1[i]==true && mp2[i]==true)
            return i;
    }
    if(min1 < min2)
        return min1*10 + min2;
    else
        return min2*10 + min1;
}
```

##### 2. [找到最大开销的子字符串](https://leetcode.cn/problems/find-the-substring-with-maximum-cost/): `前缀和` `dp`
> 构建`values[]`数组后, 使用「`前缀和` + minLeft」或者「转移`dp`」的方法解决[LC53. 最大子数组和](/workspace/53.%E6%9C%80%E5%A4%A7%E5%AD%90%E6%95%B0%E7%BB%84%E5%92%8C.cpp)即可

###### 方法一: dp
```CPP
// dp[i]: 严格以s[i]结尾的最大子数组和
int maximumCostSubstring(string s, string chars, vector<int>& vals) {
    int n = s.size();
    vector<int> values(26, 0);
    for(int i=0; i<26; i++)
        values[i] = i+1;
    for(int i=0; i<chars.size(); i++){
        values[chars[i]-'a'] = vals[i];
    }
    int ans = 0;
    vector<int> dp(n+1, 0);
    for(int i=1; i<=n; i++){
        dp[i] = (dp[i-1]>0) ? dp[i-1]+values[s[i-1]-'a'] : values[s[i-1]-'a'];
        ans = max(ans, dp[i]);
    }
    return ans;
}
```

###### 方法二: prefixSum + minLeft
```CPP
int maximumCostSubstring(string s, string chars, vector<int>& vals) {
    int n = s.size();
    vector<int> values(26, 0);
    for(int i=0; i<26; i++)
        values[i] = i+1;
    for(int i=0; i<chars.size(); i++){
        values[chars[i]-'a'] = vals[i];
    }
    int ans = 0;
    vector<int> pre(n+1, 0);
    int leftMin = 0;
    for(int i=1; i<=n; i++){
        pre[i] = pre[i-1] + values[s[i-1]-'a'];
        ans = max(ans, pre[i] - leftMin);
        leftMin = min(leftMin, pre[i]);
    }
    return ans;
}
```

##### 3. [使子数组元素和相等](https://leetcode.cn/problems/make-k-subarray-sums-equal/): `裴蜀定理` `gcd` `中位数贪心`

> **中位数贪心**
>
> ![中位数贪心](/appendix/%E4%B8%AD%E4%BD%8D%E6%95%B0%E8%B4%AA%E5%BF%83.png)
>
> **[裴蜀定理](https://oi-wiki.org/math/number-theory/bezouts/)**
> 
> ![LC2607](/appendix/LC2607.png)

```CPP
int gcd(int n, int k){
    return (n%k==0)?k:gcd(k, n%k);
}
long long makeSubKSumEqual(vector<int>& arr, int K) {
    int n = arr.size();
    long long ans = 0;
    int k = gcd(n, K);
    // 划分为gcd(n, K)个组, 每个组内所有元素相等
    vector<vector<int>> subArrs(k);
    for(int i=0; i<n; i++){
        subArrs[i%k].push_back(arr[i]);
    }
    for(int i=0; i<k; i++){
        sort(subArrs[i].begin(), subArrs[i].end());
        int mid = subArrs[i][subArrs[i].size()/2];
        for(int x: subArrs[i]){
            ans += abs(x - mid);
        }
    }
    return ans;
}
```

##### 4. [图中的最短环](https://leetcode.cn/problems/shortest-cycle-in-a-graph/): `BFS` `最短路` `最短环`

> - 没有边权的最短路(环) ➡️ `BFS`
>
> - 如何判断是环路还是同一条边的往返 ➡️ 加入队列的同时记录一个`pre`, 记录当前节点`v`的上一个节点是`cur`
>
> - 记录路径边数 ➡️ `dist[N]`数组

```CPP
typedef pair<int, int> PII;
int BFS(vector<vector<int>> &g, int u){
    int n = g.size();
    queue<PII> q;
    q.push({u, -1});
    vector<int> dist(n, -1);
    dist[u] = 0;
    int pre = -1;
    while(!q.empty()){
        int cur = q.front().first;
        int pre = q.front().second;
        q.pop();
        for(int i=0; i<g[cur].size(); i++){
            int v = g[cur][i];
            if(dist[v] == -1){
                dist[v] = dist[cur] + 1;
                q.push({v, cur});               // 记录当前节点`v`的上一个节点是`cur`
            }
            else if(v != pre){
                return (dist[cur]+1) + dist[v]; // 两条路线都可以到v, 合并起来就是一条环路
            }
        }
    }
    return INT_MAX;
}
int findShortestCycle(int n, vector<vector<int>>& edges) {
    vector<vector<int>> g(n, vector<int>());
    for(vector<int> &e: edges){
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }
    int ans = INT_MAX;
    for(int u=0; u<n; u++){
        ans = min(ans, BFS(g, u));
    }
    return ans < INT_MAX ? ans : -1;
}
```