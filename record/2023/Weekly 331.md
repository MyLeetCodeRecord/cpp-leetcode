### Weekly 331

#### 1. [从数量最多的堆取走礼物](https://leetcode.cn/problems/take-gifts-from-the-richest-pile/): `priority_queue`

```CPP
long long pickGifts(vector<int>& gifts, int k) {
    priority_queue<long long> pq;
    for(int g : gifts)
        pq.push(g);
    while(k > 0){
        int cur = pq.top();
        if(cur == 1)
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


#### 2. [统计范围内的元音字符串数](https://leetcode.cn/problems/count-vowel-strings-in-ranges/): `前缀和`

```CPP
unordered_set<char> st = {'a','e','i','o','u'};
bool check(string word){
    if(st.find(word[0])==st.end())
        return false;
    if(st.find(word.back())==st.end())
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


#### 3. [打家劫舍IV](https://leetcode.cn/problems/house-robber-iv/): `二分` `dp`

```CPP
bool check(vector<int>& nums, int limit, int k){
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = (nums[0]<=limit) ? 1 : 0;
    dp[1] = max(dp[0], ((nums[1]<=limit) ? 1 : 0));
    for(int i=2; i<n; i++){
        if(nums[i]<=limit)
            dp[i] = max(dp[i-1], dp[i-2]+1);
        else
            dp[i] = dp[i-1];
    }
    return (dp[n-1] >= k);
}
int minCapability(vector<int>& nums, int k) {
    int n = nums.size();
    if(n==1 && k==1)
        return nums[0];
    int l = 1, r = 1e9;
    // 左端点模板
    while(l < r){
        int mid = (l+r)/2;
        if(check(nums, mid, k)==false)
            l = mid + 1;
        else
            r = mid;
    }
    return r;
}
```