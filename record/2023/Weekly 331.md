#### Weekly 331

##### 1. [从数量最多的堆取走礼物](https://leetcode.cn/problems/take-gifts-from-the-richest-pile/): `priority_queue` `模拟`

```CPP
long long pickGifts(vector<int>& gifts, int k) {
    priority_queue<long long> pq;  // 将元素插入优先队列(大顶堆)中
    for(int g : gifts)
        pq.push(g);
    while(k > 0){
        int cur = pq.top();
        if(cur == 1)    // 如果当前最大元素是1, 可以提前终止
            break;
        pq.pop();
        pq.push(sqrt(cur));
        k--;
    }
    long long ans = 0;
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }
    return ans;
}
```


##### 2. [统计范围内的元音字符串数](https://leetcode.cn/problems/count-vowel-strings-in-ranges/): `前缀和`
> 从左到右统计以元音开始和结束的单词个数 => `prefixSum`

```CPP
unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
bool check(string word){
    if(st.find(word[0])==st.end() || st.find(word.back())==st.end())
        return false;
    return true;
}
vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    int n = words.size();
    vector<int> preSum(n+1, 0);
    for(int i=1; i<=n; i++){
        preSum[i] = preSum[i-1] + (check(words[i-1])==true);
    }
    int m = queries.size();
    vector<int> ans(m, 0);
    for(int i=0; i<m; i++){
        ans[i] = preSum[queries[i][1]+1] - preSum[queries[i][0]];
    }
    return ans;
}
```


##### 3. [打家劫舍IV](https://leetcode.cn/problems/house-robber-iv/): `二分` `dp`
> 「最小的最大值」且具有「单调性」➡️ `二分`
>
> `check(mid)`检查`mid`作为最大值的方案是否存在(是否可以选出大于等于`k`个房屋进行偷盗), 满足:
> - 选择的房屋`nums[i] <= mid`
> - 不能偷盗相邻的房屋
>
> `check(mid)`类似[LC198. 打家劫舍](/markdown/%E4%B8%93%E9%A2%98%20-%20DP%20-%20%E5%BC%BA%E7%9B%97%E9%97%AE%E9%A2%98.md#lc198-%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8D), 可以用`dp`解决
> - `dp[i]`表示`0~i`的房间中满足上面条件的「最大盗窃房屋数」
>   - 如果`nums[i] <= limit`, 有「偷」or「不偷」两种选择, `dp[i] = max(dp[i-1], dp[i-2]+1)`
>   - 如果`nums[i] > limit`, 只有「不偷」一种选择, `dp[i] = dp[i-1]`
> - `check`返回值为`dp[n-1] >= k`

```CPP
// LC198. 打家劫舍
bool check(vector<int>& nums, int limit, int k){
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = (nums[0]<=limit) ? 1 : 0;
    dp[1] = max(dp[0], ((nums[1]<=limit) ? 1 : 0));
    for(int i=2; i<n; i++){
        if(nums[i]<=limit)  // 偷 or 不偷
            dp[i] = max(dp[i-1], dp[i-2]+1);
        else                // 不偷
            dp[i] = dp[i-1];
    }
    return (dp[n-1] >= k);
}
int minCapability(vector<int>& nums, int k) {
    int n = nums.size();
    if(n==1 && k==1)
        return nums[0];
    // 左端点模板
    int l = 1, r = 1e9;
    while(l < r){
        int mid = (l+r)/2;
        if(check(nums, mid, k)==false)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
```


##### 4. [重排水果](https://leetcode.cn/problems/rearranging-fruits/): `思维题` -> [灵神题解](https://www.bilibili.com/video/BV1sG4y1T7oc/?spm_id_from=333.337.search-card.all.click&vd_source=e60de8162f155cdd464b9f11c355e633)

```CPP
long long minCost(vector<int>& basket1, vector<int>& basket2) {
    // 最小值 => 工具人
    // e.g. 交换两个数组的11, 12, 直接交换cost=min(11, 12)=11
    //      如果借助一个工具人min=5, cost=5+5=10
    // 求所有水果里的最小值
    int minVal = 1e9;
    unordered_map<int, int> mp;
    for(int i=0; i<basket1.size(); i++){
        minVal = min(minVal, min(basket1[i], basket2[i]));
        mp[basket1[i]]++;
        mp[basket2[i]]--;
    }
    vector<int> a, b;
    for(auto &[k, v]: mp){
        if(v % 2 == 1)
            return -1;
        if(v > 0){
            for(int i=0; i<v/2; i++)
                a.push_back(k);
        }
        if(v < 0){
            v = -v;
            for(int i=0; i<v/2; i++)
                b.push_back(k);
        }
    }
    // a从小到大排序, b从大到小排序
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    long long ans = 0;
    for(int i=0; i<a.size(); i++){
        ans += min(min(a[i], b[i]), minVal*2);
    }
    return ans;
}
```