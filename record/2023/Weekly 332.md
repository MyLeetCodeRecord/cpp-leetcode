#### Weekly 332

#### 1. [找出数组的串联值](https://leetcode.cn/problems/find-the-array-concatenation-value/): `模拟`

```CPP
long long findTheArrayConcVal(vector<int>& nums) {
    int n = nums.size();
    string str = "";
    long long num = 0;
    for(int i=0; i<n/2; i++){
        str = to_string(nums[i]) + to_string(nums[n-i-1]);
        num += stoi(str);
    }
    // 剩余一个
    if(n % 2 == 1){
        str = to_string(nums[n/2]);
        num += stoi(str);
    }
    return num;
}
```


#### 2. [统计公平数对的数目](https://leetcode.cn/problems/count-the-number-of-fair-pairs/): `二分`

```CPP
// 左端点
int binary_search_left(vector<int>& q, int l, int r, int target){
    while(l < r){
        int mid = (l+r)/2;
        if(q[mid] < target)
            l = mid+1;
        else
            r = mid;
    }
    return l;
}
// 右端点
int binary_search_right(vector<int>& q, int l, int r, int target){
    while(l < r){
        int mid = (l+r+1)/2;
        if(q[mid] > target)
            r = mid-1;
        else
            l = mid;
    }
    return r;
}
long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    long long ans = 0;
    for(int i=0; i<n; i++){
        int lbound = binary_search_left(nums, i+1, n-1, lower-nums[i]);
        int rbound = binary_search_right(nums, i+1, n-1, upper-nums[i]);
        if(lbound < n && nums[i]+nums[lbound]>=lower
            && rbound > i && nums[i]+nums[rbound]<=upper)
            ans += (rbound - lbound + 1);
    }
    return ans;
}
```


##### 3. [子字符串异或查询](https://leetcode.cn/problems/substring-xor-queries/): `字符串匹配` `预处理`

> 这题表面是字符串匹配, 实际上`pattern`的长度不会超过`31`, 并且`pattern`查询的数量很大
> 
> 但原字符串`s`的长度为`10^4`, 及时「先预处理出所有长度不超过31的子串及该子串第一次出现位置存入`map`中」 => 复杂度不会超过`O(30*10^4)≈O(10^5)`
>
> 然后对于每个`query`, 在`map`中查询即可, 找不到返回`{-1, -1}`, 否则返回`{mp[t], mp[t]+t.size()-1}`

```CPP
vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
    int n = s.size();
    unordered_map<string, int> mp;
    for(int len=1; len<=31; len++){
        for(int i=0; i+len-1<n; i++){
            if(s[i] == 0)
                continue;
            string sub = s.substr(i, len);
            if(mp.find(sub) == mp.end())
                mp[sub] = i;
        }
    }
    vector<vector<int>> ans;
    for(vector<int> q: queries){
        string t = getBinary(q[0]^q[1]);
        if(mp.find(t) != mp.end())
            ans.push_back({mp[t], mp[t] + (int)t.size() - 1});
        else
            ans.push_back({-1,-1});
    }
    return ans;
}
string getBinary(int n){
    if(n == 0)
        return "0";
    string ans;
    while(n != 0){
        if(n & 1)
            ans = "1"+ans;
        else
            ans = "0"+ans;
        n >>= 1;
    }
    return ans;
}
```