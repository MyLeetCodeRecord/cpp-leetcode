#### Weekly 319

##### 1. [温度转换](https://leetcode.cn/problems/convert-the-temperature/): 加减法


##### 2. [最小公倍数为 K 的子数组数目](https://leetcode.cn/problems/number-of-subarrays-with-lcm-equal-to-k/)

> 这题的数据范围`1000`, 看起来就能`暴力`
> 
> 难点在于求每段数组的`lcm`, 于是百度了一下...再加上一层枚举左端点, 就过了...

> **两数的最小公倍数**
> 
> `lcm(a, b) = a * b / gcd(a, b)`
> 
> **数组的最小公倍数 => 传递**
> 
> 用`lcm`记录`nums[:j-1]`这段数组的最小公倍数, `lcm`初始化为`1`
> 
> 可以得到, `lcm(nums[:j]) = lcm * nums[j] / gcd(lcm, nums[j])`
> 
> 由于`nums[j]`每个数大于`1`, 因此一旦`lcm > target`, 应该提前`break`这个`起点i`取值

```CPP
// 最大公约数
int gcd(int a, int b){
    if(a % b == 0)
        return b
    return gcd(b, a % b);
}
// 求数组的最小公倍数
int getLCM(vector<int> nums, int start, int end){
    // 用long long初始化, 防止乘积溢出, 先除后乘就不用担心了
    long long lcm = 1;
    for(int j=start; j<=end; j++){
        // 先除后乘更好一些, 这里为了方便理解没有调换
        lcm = lcm * nums[j] / gcd(lcm, nums[j]);
    }
    return lcm;
}
```

> **完整实现**
```CPP
int gcd(int a, int b){
    if(a%b==0)
        return b;
    return gcd(b, a%b);
}
int subarrayLCM(vector<int>& nums, int k) {
    int ans = 0;
    for(int i=0; i<nums.size(); i++){
        long long lcm = 1;  // 中间过程用long long防止溢出
        for(int j=i; j<nums.size(); j++){
            lcm = lcm * nums[j] / gcd(lcm, nums[j]);
            if(lcm == k)
                ans++;
            if(lcm > k)
                break;
        }
    }
    return ans;
}
```


##### 3. [逐层排序二叉树所需的最少操作数目](https://leetcode.cn/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/)

###### 直接交换

> 读一遍题就可以发现是**每次遍历一整个layer**的`层序遍历(BFS)`
> 
> 遇到不匹配的, 交换一次放到指定位置, 直到指针扫完整个列表, **需要注意的是发生交换的话, 指针不能后移**
> 
> 看了灵神和y总的视频, 都是`置换环/环图`来求最小交换次数`ans = n - #loop`...但做周赛的时候用的是"直接交换回正确位置"的做法, 也都过了
> 
> 其实, 交换只发生在每个组(一个环里的所有节点作为一个组)当中, 交换次数还是等于`circle_size-1`...所以两种方法应该是**等价的**
>
> ⬆️ 不推荐

###### [置换环](/markdown/%E4%B8%93%E9%A2%98%20-%20%E7%BD%AE%E6%8D%A2%E7%8E%AF.md) ✅

> ![置换环](/appendix/%E7%BD%AE%E6%8D%A2%E7%8E%AF-1.png)
> 
> 因此, `ans = ∑(cycle_size-1)`
>
> 同时, 每个节点元素之出现一个环路中, 共有`N`个元素, 则`ans = N-(#cycle)`
> 
> ![置换环-cn](/appendix/%E7%BD%AE%E6%8D%A2%E7%8E%AF.png)

```CPP
int minSwap(vector<int>& arr){
    int n = arr.size();
    // map存储的是元素应该放在的正确位置
    vector<int> copy = arr;
    sort(copy.begin(), copy.end());
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[copy[i]] = i;
    }
    // 找到所有环路
    vector<bool> visited(n, false);
    int loopNum = 0;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            // 遍历一个环, 标记所有节点为visited=true
            int j = i;
            while(!visited[j]){
                visited[j] = true;
                j = mp[arr[j]];
            }
            loopNum++;
        }
    }
    return n - loopNum;
}
int BFS(TreeNode* root){
    int ans = 0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> layer;
        int _size = q.size();
        for(int i=0; i<_size; i++){
            TreeNode* cur = q.front();
            q.pop();
            layer.push_back(cur->val);
            if(cur->left != NULL)
                q.push(cur->left);
            if(cur->right != NULL)
                q.push(cur->right);
        }
        ans += minSwap(layer);
    }
    return ans;
}
int minimumOperations(TreeNode* root) {
    return BFS(root);
}
```


##### 4. [不重叠回文子字符串的最大数目](https://leetcode.cn/problems/maximum-number-of-non-overlapping-palindrome-substrings/)

###### **Step 1**: 构建回文子串 - `递归`, `dp`
```CPP
vector<vector<bool> > isHW(n+1, vector<bool>(n+1, false));
for(int len=1; len<=n; len++){
    for(int i=1; i+len-1<=n; i++){
        int j = i + len - 1;
        if(len == 1)
            isHW[i][j] = true;
        else if(s[i-1]==s[j-1] && (len==2 || isHW[i+1][j-1]))
            isHW[i][j] = true;
    }
}
```
###### **Step 2**: `dp`求不重叠回文子串的最大数目
```CPP
vector<int> dp(n+1);
for(int i=1; i<=n; i++){
    dp[i] = dp[i-1];
    for(int j=i-k; j>0; j--){
        // 如果s[j+1, i]是回文, 则dp[i]可以从dp[j]转移过来
        if(isHW[j+1][i])
            dp[i] = max(dp[i], dp[j] + 1);
    }
}
return dp[n];
```

###### 完整实现
```CPP
// 二维dp预处理出所有子串是否为回文, 为了方便从1开始
vector<vector<bool>> initSubstr(string s){
    int n = s.size();
    vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
    for(int i=1; i<=n; i++){
        dp[i][i] = true;
        if(i != n)
            dp[i][i+1] = (s[i-1]==s[i]);
    }
    for(int len=3; len<=n; len++){
        for(int i=1; i+len-1<=n; i++){
            int j = i+len-1;
            if(s[i-1]==s[j-1])
                dp[i][j] = dp[i+1][j-1];
        }
    }
    return dp;
}
int maxPalindromes(string s, int k) {
    int n = s.size();
    vector<vector<bool> > isHW = initSubstr(s);
    vector<int> dp(n+1, 0);
    for(int i=k; i<=n; i++){
        dp[i] = dp[i-1];        // !!!
        for(int j=i-k; j>=0; j--){
            if(isHW[j+1][i]==true)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    return dp[n];
}
```
